#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 100 * 1000 + 10;
const ll INF = 1e18;
int n,m;
bool c[nax];
bool visited[nax];
ll add[nax];
vector<pair<int,int> > V[nax];
bool ok = 1;
ll w[2], cnt[2], s;
vector<ll> used;
vector<ll> val[2];

void dfs(int x) {
	visited[x] = 1;
	used.PB(x);
	cnt[c[x]]++;
	s += add[x];
	val[c[x]].PB(add[x]);
	for(auto nbh : V[x]) {
		if(!visited[nbh.ST]) {
			c[nbh.ST] = 1 - c[x];
			if(nbh.ND == 0) {
				add[nbh.ST] = -add[x];
			} else {
				add[nbh.ST] = -add[x] + 1;
			}
			dfs(nbh.ST);
		} else {
			if(c[x] != c[nbh.ST]) {
				int sum = add[x] + add[nbh.ST] + 1;
				if(nbh.ND + 1 != sum) ok = 0;
			} else {
				int sum = nbh.ND + 1 - add[x] - add[nbh.ST];
				if(w[c[x]] == -INF) {
					w[c[x]] = sum;
				} else if(w[c[x]] != sum) {
					ok = 0;
				}
			}
		}
	}
}

long double ans[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int a,b,i = 1; i <= m; ++i) {
		int cc;
		cin >> a >> b >> cc;
		cc--;
		V[a].PB({b,cc});
		V[b].PB({a,cc});
	}
	for(int ii = 1; ii <= n; ++ii) {
		if(visited[ii]) continue;
		used = val[0] = val[1] = {};
		ok = 1;
		w[0] = w[1] = -INF;
		cnt[0] = cnt[1] = s = 0;
		dfs(ii);
		if(!ok) {
			cout << "NO";
			return 0;
		}
		if(w[0] == -INF && w[1] == -INF) {
			//ans += (s + min(cnt[0], cnt[1]));
			sort(val[0].begin(), val[0].end());
			sort(val[1].begin(), val[1].end());
			ll s0 = 0, s1 = 0, p1 = 0, p0 = 0;
			for(ll x : val[0]) s0 += x;
			for(ll x : val[1]) s1 += x;
			pair<ll,ll> best = {INF, -1};
			int y = 0, y2 = 0;
			ll l = (min((val[1].size() == 0 ? INF : val[1][0]), (val[0].size() == 0 ? -INF :val[0][0])));
			ll r = (max((val[1].size() == 0 ? -INF :val[1].back()), (val[0].size() == 0 ? -INF : val[0].back())));
			for(ll i = min(-r, 1 + l); i <= max(-l, 1+r); ++i) {
				ll wyn = 0;
				for(ll x : val[0]) wyn += llabs(x + i);
				for(ll x : val[1]) wyn += llabs(1 - i +x);
				best = min(best, {wyn, i});
			}
				
			//for(int i = 0; i < (int)val[0].size(); ++i) {
				//ll cur = val[0][i];
				//while(y < (int)val[1].size() && val[1][y] < - (1 + cur)) {
					//p1 += val[1][y];
					//y++;
				//}
				//ll wyn = (ll)cur * i - p0 + (ll)(s0 - p0) - (ll)cur * ((int)val[0].size() - i);
				//wyn +=  (ll)(1 + cur) * ((int)val[1].size() - y) + (s1 - p1) + llabs((ll)(1 + cur) * y + p1);
				//p0 += val[0][i];
				//best = min(best, {wyn, -cur});
			//}
			//p1 = p0 = 0;
			//y = 0;
			//for(int i = 0; i < (int)val[1].size(); ++i) {
				//ll cur = val[1][i];
				//while(y < (int)val[0].size() && val[0][y] < - (1 +cur)) {
					//p0 += val[0][y];
					//y++;
				//}
				//ll wyn = (ll)cur * i - p1+ (ll)(s1 - p1) - (ll)cur * ((int)val[1].size() - i);
				//wyn += (1 + cur) * ((int)val[0].size() - y) + (s0 - p0) + abs(p0 + (ll)(1 + cur)*y);
				//wyn += -(-1 - cur) * ((int)val[0].size() - y) + (s0 - p0) + (ll)(-1-cur) * y - p0;
				//wyn +=  (ll)(1 + cur) * ((int)val[0].size() - y) + (s0 - p0) + llabs((ll)(1 + cur) * y + p0);
				//p1 += val[1][i];
				//best = min(best, {wyn, cur + 1});
			//}
			for(int x : used) {
				if(c[x]) {
					ans[x] = add[x] + 1 - best.ND;
				} else {
					ans[x] = add[x] + best.ND;
				}
			}
		} else if(w[0] != -INF && w[1] != -INF) {
			if(w[0] + w[1] != 2) {
				cout << "NO";
				return 0;
			}
			for(int x : used) {
				if(c[x]) {
					ans[x] = (long double)w[1] / 2.0 + add[x];
				} else {
					ans[x] = (long double)w[0] / 2.0 + add[x];
				}
			}
			//ans += (s + (double)(cnt[0] * w[0] + cnt[1] * w[1]) / 2.0);
		} else if(w[0] == -INF) {
			w[0] = 2 - w[1];
			for(int x : used) {
				if(c[x]) {
					ans[x] = (long double)w[1] / 2.0 + add[x];
				} else {
					ans[x] = (long double)w[0] / 2.0 + add[x];
				}
			}
			//ans += (s + (double)(cnt[0] * w[0] + cnt[1] * w[1]) / 2.0);
		} else {
			w[1] = 2 - w[0];
			for(int x : used) {
				if(c[x]) {
					ans[x] = (long double)w[1] / 2.0 + add[x];
				} else {
					ans[x] = (long double)w[0] / 2.0 + add[x];
				}
			}
			//ans += (s + (double)(cnt[0] * w[0] + cnt[1] * w[1]) / 2.0);
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
}