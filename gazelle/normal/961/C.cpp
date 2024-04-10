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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<vector<string>> p(4,vector<string>(n));
	REP(i,4) REP(j,n) cin>>p[i][j];
	vector<ll> perm={0,1,2,3};
	ll ans=INF;
	do {
		ll rep=0;
		REP(i,2*n) {
			REP(j,2*n) {
				if(i<n) {
					if(j<n) {
						if(((i%2)^(j%2))!=p[perm[0]][i][j]-'0') rep++;
					}
					else {
						if(((i%2)^(j%2))!=p[perm[1]][i][j-n]-'0') rep++;
					}
				} else {
					if(j<n) {
						if(((i%2)^(j%2))!=p[perm[2]][i-n][j]-'0') rep++;
					}
					else {
						if(((i%2)^(j%2))!=p[perm[3]][i-n][j-n]-'0') rep++;
					}
				}
			}
		}
		ans=min(ans,min(rep,4*n*n-rep));
	} while(next_permutation(ALL(perm)));
	cout<<ans<<endl;
}