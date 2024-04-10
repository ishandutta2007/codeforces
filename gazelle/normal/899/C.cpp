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
#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	vector<ll> ans;
	ll g=n*(n+1)/2;
		if(g%2==0) {
			cout<<0<<endl;
			g/=2;
			ll crt=n;
			while(crt<=g) {
				ans.pb(crt);
				g-=crt;
				crt--;
			}
			if(g!=0) ans.pb(g);
		} else {
			cout<<1<<endl;
			g/=2;
			ll crt=n;
			while(crt<=g) {
				ans.pb(crt);
				g-=crt;
				crt--;
			}
			if(g!=0) ans.pb(g);
		}
	cout<<(ll)ans.size()<<" ";
	DUMP(ans);
}