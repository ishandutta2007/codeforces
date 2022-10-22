#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e13 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
const int MAXT = 1e6 + 7;

struct Kek{
	int t, c, u;
	bool type;
};

Kek init(int t, int c, bool type, int u){
	Kek res = *new Kek();
	res.t = t;
	res.c = c;
	res.u = u;
	res.type = type;
	return res;
}

vector <Kek> tml;
multiset <int> best1[MAXN], best2[MAXN];

bool comp(Kek a, Kek b){
	return (a.t < b.t) || (a.t == b.t && !a.type && b.type);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i){
		best1[i] = { MOD };
		best2[i] = { MOD };
	}

	int t, u, v, c;
	for (int i = 0; i < m; ++i){
		cin >> t >> u >> v >> c;
		if (!v){
			tml.push_back(init(t + 1, c, true, u));
		}
		else{
			tml.push_back(init(t - k + 1, c, false, v));
			best2[v].insert(c);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i){
		ans += *best1[i].begin();
		ans += *best2[i].begin();
	}

	sort(tml.begin(), tml.end(), comp);

	int res = MOD;
	for (Kek e : tml){
		if (e.type){
			ans -= *best1[e.u].begin();
			best1[e.u].insert(e.c);
			ans += *best1[e.u].begin();
		}
		else{
			ans -= *best2[e.u].begin();
			best2[e.u].erase(best2[e.u].find(e.c));
			ans += *best2[e.u].begin();
		}

		res = min(res, ans);
	}

	if (res >= MOD){
		cout << "-1\n";
	}
	else{
		cout << res << '\n';
	}

	return 0;
}