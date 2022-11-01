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
#include<complex>
#include<unordered_map>

#define INF 1000000000ll
#define MOD 1000000007ll
#define EPS 1e-8

#define REP(i, m) for(long long i = 0; i < m; ++i)
#define FOR(i, n, m) for(long long i = n; i < m; ++i)
#define ALL(v) v.begin(), v.end()
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;


int main() {
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<vector<int> > tab(n,vector<int>(m));
	REP(i,n) {
		REP(j,m) cin>>tab[i][j];
	}
	ll res=0;
	res+=n*m;
	for(int i=0; i<n; ++i) {
		int wc=0,bc=0;
		for(int j=0; j<m; ++j) {
			if(tab[i][j]==0) ++wc;
			else ++bc;
		}
		res+=(1ll<<wc)-wc-1;
		res+=(1ll<<bc)-bc-1;
	}
	for(int i=0; i<m; ++i) {
		int wc=0,bc=0;
		for(int j=0; j<n; ++j) {
			if(tab[j][i]==0) ++wc;
			else ++bc;
		}
		res+=(1ll<<wc)-wc-1;
		res+=(1ll<<bc)-bc-1;
	}
	cout<<res<<endl;
}