#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#include<fstream>
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

class Trie {
private:
	long long number;	//  -1
	long long count;	// 
	int depth;	//  bit 
	Trie* l;	//  NULL
	Trie* r;	//  NULL
public:
	Trie(long long _number=-1, long long _count=1, int _depth=0) {
		// 
		number=_number;
		count=_count;
		depth=_depth;
		l=NULL;
		r=NULL;
	}
	void insert(long long n, long long c=1) {
		// n  c 
		bitset<64> bi1(n);
		bitset<64> bi2(number);
		if(number==-1) {
			if(l==NULL&&r==NULL) {	// 
				number=n;
				count=c;
				return;
			}
			if(bi1[63-depth]==0) {
				if(l!=NULL) l->insert(n,c);
				else l=new Trie(n,c,depth+1);
			} else {
				if(r!=NULL) r->insert(n,c);
				else r=new Trie(n,c,depth+1);
			}
		} else {
			if(number==n) {
				count++;
				return;
			}
			if(bi1[63-depth]==0) l=new Trie(n,c,depth+1);
			else r=new Trie(n,c,depth+1);
			if(bi2[63-depth]==0) {
				if(l!=NULL) l->insert(number,count);
				else l=new Trie(number,count,depth+1);
			} else {
				if(r!=NULL) r->insert(number,count);
				else r=new Trie(number,count,depth+1);
			}
			count=0;
			number=-1;
		}
	}
	long long find(long long n) {
		// n  XOR 
		bitset<64> bi(n);
		if(number!=-1) return number;
		if(l==NULL&&r==NULL) return -1; // 
		long long ret=0;
		if(bi[63-depth]==1) {
			if(l!=NULL) ret=l->find(n);
			else ret=r->find(n);
		} else {
			if(r!=NULL) ret=r->find(n);
			else ret=l->find(n);
		}
		return ret;
	}

	void erase(long long n, bool* d=NULL) {
		// n  1 n 
		bitset<64> bi(n);
		if(number!=-1) {
			count--;
			if(count==0&&d!=NULL) *d=true;
			return;
		}
		bool f=false;
		if(bi[63-depth]==0) {
			if(l!=NULL) {
				l->erase(n,&f);
				if(f) {
					if(r==NULL&&d!=NULL) *d=true;
					else l=NULL;
				}
			} else return;
		} else {
			if(r!=NULL) {
				r->erase(n,&f);
				if(f) {
					if(l==NULL&&d!=NULL) *d=true;
					else r=NULL;
				}
			} else return;
		}
		return;
	}
};

int main() {
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> a(n);
	vector<ll> p(n);
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>p[i];
	Trie trie;
	REP(i,n) trie.insert(p[i]);
	vector<ll> ans(n);
	REP(i,n) {
		ll tmp=trie.find(a[i]^((1ll<<63)-1));
		ans[i]=a[i]^tmp;
		trie.erase(tmp);
	}
	DUMP(ans);
}