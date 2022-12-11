#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

int n, m;
vector<int> g[2][200007];

const int BB = 42; // /!!!!!!

ll dp[200007][BB];
int step[500007];
ll step2[50];

//int mi[200007][2];

const ll INF = 1e18;


pair<int, ll> dp2[200007][2];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	step[0] = 1;
	step2[0] = 1;
	for (int i = 1; i < 500007; ++i) {
		step[i] = step[i - 1] * (ll)2 % mod;
		if (i < 50)
		step2[i] = step2[i - 1] * 2;
	}

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int w1, w2;
		cin >> w1 >> w2;
		--w1; --w2;
		g[0][w1].pb(w2);
		g[1][w2].pb(w1);
	}

	for (int i = 0; i < n; ++i) for (int j = 0; j < BB; ++j) dp[i][j] = INF; 
	dp[0][0] = 0;

	set<pair<ll, pair<int, int>>> se;
	se.insert(mp(0, mp(0, 0)));

	while (se.size()) {
		auto now = *se.begin();
	//	cout << now.x << ' ' << now.y.x << ' ' << now.y.y << endl;
		se.erase(se.begin());
		int f = now.y.y % 2;
		for (int to : g[f][now.y.x]) {
			ll cost = now.x + 1;
			if (dp[to][now.y.y] > cost) {
				se.erase({dp[to][now.y.y], {to, now.y.y}});
				dp[to][now.y.y] = cost;
				se.insert({cost, {to, now.y.y}});
			}
		}
		if (now.y.y == BB - 1) continue;
		if (dp[now.y.x][now.y.y + 1] > dp[now.y.x][now.y.y] + step2[now.y.y]) {
			se.erase({dp[now.y.x][now.y.y + 1], {now.y.x, now.y.y + 1}});
			dp[now.y.x][now.y.y + 1] = dp[now.y.x][now.y.y] + step2[now.y.y];
			se.insert({dp[now.y.x][now.y.y + 1], {now.y.x, now.y.y + 1}});
		}
	}

	ll ans = INF;
	for (int i = 0; i < BB; ++i) ans = min(ans, dp[n - 1][i]);

//// 2 

/*
	for (int i = 0; i < n; ++i) mi[i][0] = mi[i][1] = 1e9;
	mi[0][0] = 0;

	deque<pair<int, int> > de;
	de.pb({0, 0});

	while (de.size()) {
		auto [v, type] = de.front();
		de.pop_front();
		for (int to : g[type][v]) {
			if (mi[to][type] > mi[v][type]) {
				mi[to][type] = mi[v][type];
				de.push_front({to, type});
			}
		}
		if (mi[v][type ^ 1] > mi[v][type] + 1) {
			mi[v][type ^ 1] = mi[v][type] + 1;
			de.push_back({v, type ^ 1});
		}
	}

	int cnt = min(mi[n - 1][0], mi[n - 1][1]); */

/// 3

	//cout << cnt << endl;

	for (int i = 0; i < n; ++i) dp2[i][0] = dp2[i][1] = {1e9, INF}; 
	dp2[0][0] = {0, 0};

	set<pair<pair<int, ll>, pair<int, int>>> se2;
	se2.insert(mp(mp(0, 0), mp(0, 0)));

	while (se2.size()) {
		auto now = *se2.begin();
	//	cout << now.x << ' ' << now.y.x << ' ' << now.y.y << endl;
		se2.erase(se2.begin());
		for (int to : g[now.y.y][now.y.x]) {
			auto cost = mp(now.x.x, now.x.y + 1);
			if (dp2[to][now.y.y] > cost) {
				se2.erase({dp2[to][now.y.y], {to, now.y.y}});
				dp2[to][now.y.y] = cost;
				se2.insert({dp2[to][now.y.y], {to, now.y.y}});
			}
		}
		if (dp2[now.y.x][now.y.y ^ 1] > mp(now.x.x + 1, now.x.y)) {
			se2.erase({dp2[now.y.x][now.y.y ^ 1], {now.y.x, now.y.y ^ 1}});
			dp2[now.y.x][now.y.y ^ 1] = {now.x.x + 1, now.x.y};
			se2.insert({dp2[now.y.x][now.y.y ^ 1], {now.y.x, now.y.y ^ 1}});
		}
	}

	pair<int, ll> now = min(dp2[n - 1][0], dp2[n - 1][1]);

//	cout << now.x << ' ' << now.y << endl;

	if (ans == INF) {
		ll kek = now.y % mod;
		for (int i = 0; i < now.x; ++i) {
			kek += step[i];
			if (kek >= mod) kek -= mod;
		}
		ans = kek;
	}




/// ans
	cout << ans;
}