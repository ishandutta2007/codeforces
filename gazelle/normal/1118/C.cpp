#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using pint=pair<int,int>;
using pll=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll> num(1001, 0);
	REP(i, n * n) {
		ll a;
		cin >> a;
		num[a]++;
	}
	if(n % 2 == 0) {
		REP(i, 1001) if(num[i] % 4) {
			cout << "NO" << endl;
			return 0;
		}
		vector<vector<ll>> ans(n, vector<ll>(n, 0));
		ll idx = 0;
		REP(i, n / 2) REP(j, n / 2) {
			while(num[idx] == 0) idx++;
			num[idx] -= 4;
			ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = idx;
		}
		cout << "YES" << endl;
		REP(i, n) DUMP(ans[i]);
	} else {
		ll rem1 = 1, rem2 = (n - 1);
		queue<pll> v1, v2, v4;
		REP(i, 1001) {
			if(num[i] % 2 == 1) {
				rem1--;
				v1.push(pll(i, 1));
				num[i]--;
			}
			if(num[i] % 4 == 2) {
				rem2--;
				v2.push(pll(i, 2));
				v4.push(pll(i, num[i] - 2));
			} else {
				v4.push(pll(i, num[i]));
			}
		}
		if(rem1 != 0 || rem2 < 0 || rem2 % 2) {
			cout << "NO" << endl;
			return 0;
		}
		vector<vector<ll>> ans(n, vector<ll>(n, -1));
		REP(i, n / 2 + 1) REP(j, n / 2 + 1) {
			if(i == n / 2 && j == n / 2) {
				ans[i][j] = v1.front().first;
			} else if(i == n / 2) {
				if(v2.empty()) {
					while(v4.front().second == 0) {
						v4.pop();
					}
					ans[i][j] = ans[i][n - 1 - j] = v4.front().first;
					v4.front().second -= 4;
					v2.push(pll(v4.front().first, 2));
				} else {
					ans[i][j] = ans[i][n - 1 - j] = v2.front().first;
					v2.pop();
				}
			} else if(j == n / 2) {
				if(v2.empty()) {
					while(v4.front().second == 0) {
						v4.pop();
					}
					ans[i][j] = ans[n - 1 - i][j] = v4.front().first;
					v4.front().second -= 4;
					v2.push(pll(v4.front().first, 2));
				} else {
					ans[i][j] = ans[n - 1 - i][j] = v2.front().first;
					v2.pop();
				}
			} else {
				while(v4.front().second == 0) {
					v4.pop();
				}
				ans[i][j] = ans[n - 1 - i][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = v4.front().first;
				v4.front().second -= 4;
			}
		}
		cout << "YES" << endl;
		REP(i, n) DUMP(ans[i]);
	}
	return 0;
}

/* --------------------------------------- */