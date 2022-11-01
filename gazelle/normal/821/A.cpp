#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<tuple>
#include<complex>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
#define EPS (long double) 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

using namespace std;

int main() {
	int n;
	cin>>n;
	int a[n][n];
	REP(i, n) {
		REP(j, n) cin>>a[i][j];
	}
	bool f = true;
	REP(i, n) {
		REP(j, n) {
			if(a[i][j] == 1) continue;
			bool d = false;
			REP(k, n) {
				REP(l, n) {
					if(a[i][k] + a[l][j] == a[i][j]) d = true;
				}
			}
			if(!d) f = false;
		}
	}
	if(f) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}