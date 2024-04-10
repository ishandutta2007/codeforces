#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const ll inf = 1e18;
const int maxn = 5001;

vector <vector <pair <ll, ll> > > dp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll p1, t1, p2, t2, h, s;
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	dp.resize(h + 1, vector <pair<ll, ll> >(maxn, make_pair(inf, 0LL)));
	REP(dmg, h) {
		if(!dmg) dp[dmg][0] = make_pair(0LL, 0LL);
		REP(z, maxn) {
			if(dp[dmg][z].first != inf) {
				ll cur_t = dp[dmg][z].first;
				ll puni = -dp[dmg][z].second + t1;
				ll new_dmg = dmg + p1 - s;
				new_dmg += (puni / t2) * (p2 - s);
				puni = puni % t2;
				new_dmg = min(new_dmg, (ll)h);
				if(z < maxn - 1) {
					if(dp[new_dmg][z + 1] > make_pair(cur_t + t1, -puni)) {
						dp[new_dmg][z + 1] = make_pair(cur_t + t1, -puni);
					}
				}
				//
				new_dmg = dmg + p1 + p2 - s;
				puni = -dp[dmg][z].second;
				ll adt = max(t1, t2 - puni);
				puni += adt - t2;
				new_dmg += (puni / t2) * (p2 - s);
				new_dmg += ((adt - t1) / t1) * (p1 - s);
				new_dmg = min(new_dmg, (ll)h);
				if(dp[new_dmg][0] > make_pair(cur_t + adt, 0LL)) {
					dp[new_dmg][0] = make_pair(cur_t + adt, 0LL);
				}
			}
		}
	}
	ll rj = inf;
	REP(z, maxn) rj = min(rj, dp[h][z].first);
	dp.clear();
	dp.resize(h + 1, vector <pair<ll, ll> >(maxn, make_pair(inf, 0LL)));
	REP(dmg, h) {
		if(!dmg) dp[dmg][0] = make_pair(0LL, 0LL);
		REP(z, maxn) {
			if(dp[dmg][z].first != inf) {
				ll cur_t = dp[dmg][z].first;
				ll puni = -dp[dmg][z].second + t2;
				ll new_dmg = dmg + p2 - s;
				new_dmg += (puni / t1) * (p1 - s);
				puni = puni % t1;
				new_dmg = min(new_dmg, (ll)h);
				if(z < maxn - 1) {
					if(dp[new_dmg][z + 1] > make_pair(cur_t + t2, -puni)) {
						dp[new_dmg][z + 1] = make_pair(cur_t + t2, -puni);
					}
				}
				//
				new_dmg = dmg + p2 + p1 - s;
				puni = -dp[dmg][z].second;
				ll adt = max(t2, t1 - puni);
				puni += adt - t1;
				new_dmg += (puni / t1) * (p1 - s);
				new_dmg += ((adt - t2) / t2) * (p2 - s);
				new_dmg = min(new_dmg, (ll)h);
				if(dp[new_dmg][0] > make_pair(cur_t + adt, 0LL)) {
					dp[new_dmg][0] = make_pair(cur_t + adt, 0LL);
				}
			}
		}
	}
	REP(z, maxn) rj = min(rj, dp[h][z].first);
	cout << rj << "\n";
	return 0;
}