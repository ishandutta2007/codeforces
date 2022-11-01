#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<vector<ll>> adj(n);
	REP(i,n-1) {
		ll a,b;
		cin>>a>>b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	ll c1=0, c2=0, cm=-1;
	ll posm=-1;
	REP(i,n) {
		if((ll)adj[i].size()==1) c1++;
		else if((ll)adj[i].size()==2) c2++;
		else {
			if(cm==-1) {
				cm=(ll)adj[i].size();
				posm=i;
			} else {
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	if(cm==-1) {
		cout<<"Yes"<<endl;
		cout<<1<<endl;
		ll p1=-1,p2=-1;
		REP(i,n) if((ll)adj[i].size()==1) {
			if(p1==-1) p1=i;
			else p2=i;
		}
		cout<<p1+1<<" "<<p2+1<<endl;
		return 0;
	}
	if(c1!=cm) {
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	cout<<c1<<endl;
	REP(i,n) {
		if((ll)adj[i].size()==1) {
			cout<<posm+1<<" "<<i+1<<endl;
		}
	}
}