#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
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
typedef pair<ll, ll> P;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	int n, m;
	cin>>n>>m;
	vector<vector<int> > g(n, vector<int>(m));
	REP(i, n) {
		REP(j, m) cin>>g[i][j];
	}
	int minum = INF;
	REP(i, m) minum = min(minum, g[0][i]);
	int res = -1;
	int minact = INF;
	REP(roop, minum + 1) {
		vector<vector<int> > g_copy(n, vector<int>(m));
		REP(i, n) {
			REP(j, m) g_copy[i][j] = g[i][j];
		}
		bool can = true;
		int act = (int)roop;
		vector<int> col_cnt(m, 0);
		REP(i, m) {
			g_copy[0][i] -= roop;
			col_cnt[i] = g_copy[0][i];
		}
		REP(i, m) act += col_cnt[i];
		FOR(i, 1, n) {
			int C = -1;
			REP(j, m) {
				g_copy[i][j] -= col_cnt[j];
				if(g_copy[i][j] >= 0) {
					if(C == -1) C = g_copy[i][j];
					else if(g_copy[i][j] != C) can = false;
				} else {
					can = false;
				}
			}
			act += C;
		}
		if(can && act < minact) {
			res = (int)roop;
			minact = act;
		}
	}
	if(res == -1) cout<<-1<<endl;
	else {
		cout<<minact<<endl;
		REP(i, res) {
			cout<<"row "<<1<<endl;
		}
		vector<vector<int> > g_copy(n, vector<int>(m));
		REP(i, n) {
			REP(j, m) g_copy[i][j] = g[i][j];
		}
		vector<int> col_cnt(m, 0);
		REP(i, m) {
			g_copy[0][i] -= res;
			col_cnt[i] = g_copy[0][i];
		}
		REP(i, m) {
			REP(j, col_cnt[i]) cout<<"col "<<i + 1<<endl;
		}
		FOR(i, 1, n) {
			REP(j, g_copy[i][0] - col_cnt[0]) {
				cout<<"row "<<i + 1<<endl;
			}
		}
	}
}