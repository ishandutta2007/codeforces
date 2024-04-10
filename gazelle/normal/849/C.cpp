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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8
#define rep(i,m) for(long long i=0; i<m; ++i)
#define repp(i,n,m) for(long long i=n; i<m; ++i)
#define all(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef vector<long long> vl;
typedef vector<vector<long long> > vll;

int main() {
	ios::sync_with_stdio(false);
	ll k;
	cin>>k;
	set<P> s;
	ll n=0;
	rep(i,10000) {
		n+=(i+1);
		s.insert(P(n,i+2));
	}
	string res="";
	if(k==0) {
		cout<<"a"<<endl;
		return 0;
	}
	int roc=0;
	while(k>0) {
		auto ite=upper_bound(all(s),P(k,INF));
		--ite;
		rep(i,(*ite).second) res+=char('a'+roc);
		k-=(*ite).first;
		++roc;
	}
	cout<<res<<endl;
}