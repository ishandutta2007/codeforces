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
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
int dh[4] = {1, 0, -1, 0};
int dw[4] = {0, 1, 0, -1};

int main(void) {
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<vector<int> > wa(26, vector<int>(n + 1, 0));
	REP(i, n + 1) {
		REP(j, 26) {
			if(i == 0) wa[j][i] = 0;
			else {
				if((int)(s[i - 1] - 'a') == j) wa[j][i] = wa[j][i - 1] + 1;
				else wa[j][i] = wa[j][i - 1];
			}
		}
	}
	vector<vector<int> > ob(n, vector<int>(26, 0));
	REP(i, n) {
		REP(j, 26) {
			int lb = 1;
			int ub = n + 1;
			while(ub - lb > 1) {
				int mid = (ub + lb) / 2;
				bool d = false;
				REP(k, n - mid + 1) {
					if(mid - (wa[j][k + mid] - wa[j][k]) <= i + 1) d = true;
				}
				if(d) lb = mid;
				else ub = mid;
			}
			ob[i][j] = lb;
		}
	}
	int q;
	cin>>q;
	REP(i, q) {
		int hoge;
		char gomi;
		cin>>hoge>>gomi;
		cout<<ob[hoge - 1][(int)(gomi - 'a')]<<endl;
	}
}