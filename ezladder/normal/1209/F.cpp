#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 1e9 + 7;

int n, m;

vector<pair<int, int> > g[2000007];
int sz;

void add(int w1, int w2, int val){
	int last = w2;
	while(val){
		if (val < 10){
			g[w1].pb({last, val});
			return;
		}
		int now = sz++;
		g[now].pb({last, val % 10});
		val /= 10;
		last = now;
	}
}

int ans[2000007];

bool was[2000007];

vector<int> kek[10];

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	sz = n;

	for (int i = 0; i < m; i++){
		int w1, w2;
		cin >> w1 >> w2;
		w1--; w2--;
		add(w1, w2, i + 1);
		add(w2, w1, i + 1);
	}

	vector<vector<int> > t = { { 0 } };
	was[0] = 1;

	while(1){
		if (t.size() == 0) break;
		vector<vector<int> > d;

		for (auto&& c : t){
			for (int i = 0; i < 10; i++) kek[i].clear();
			for (int v : c){
				for (auto&& to : g[v]) if (!was[to.x]){
					kek[to.y].pb(to.x);
				}
			}

			for (int val = 0; val < 10; val++){
				vector<int> now;
				for (int to : kek[val]) if (!was[to]){
					was[to] = 1;
					now.pb(to);
					ans[to] = (ans[c[0]] * (ll)10 + val) % mod; 
				}
				if (now.size()) d.emplace_back(std::move(now));
			}

		}

		swap(t, d);
	}

	for (int i = 1; i < n; i++) cout << ans[i] << "\n";
}