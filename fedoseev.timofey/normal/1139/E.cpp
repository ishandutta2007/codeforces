#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5007;

int mt[N];
int mtL[N];
int used[N];
multiset <int> g[N];

int timer = 1;

bool kuhn(int u) {
	if (used[u] == timer) return false;
	used[u] = timer;
	for (auto v : g[u]) {
		if (mt[v] == -1) {
			mt[v] = u;
			mtL[u] = v;
			return true;
		}
	}
	for (auto v : g[u]) {
		if (kuhn(mt[v])) {
			mt[v] = u;
			mtL[u] = v;
			return true;
		}
	}
	return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < N; ++i) {
    	mt[i] = mtL[i] = -1;
    }
    int n, m;
    cin >> n >> m;
    vector <int> p(n);
    vector <int> c(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    for (int i = 0; i < n; ++i) {
    	cin >> c[i];
    	--c[i];
    	g[p[i]].insert(c[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	++timer;
    	if (kuhn(i)) ++cnt;
    	else break;
    }
    int d;
    cin >> d;
    for (int i = 0; i < d; ++i) {
    	int k;
    	cin >> k;
    	--k;
    	int pr = p[k];
    	g[pr].erase(g[pr].find(c[k]));
    	if (mt[c[k]] == pr) {
    		mt[c[k]] = -1;
    		mtL[pr] = -1;
    		++timer;

    		while (cnt > pr && !kuhn(pr)) {
    			--cnt;
    			if (mtL[cnt] != -1) {
    				mt[mtL[cnt]] = -1;
    				mtL[cnt] = -1;
    			}
    			++timer;
    		}

    		for (int i = cnt; i < n; ++i) {
    			++timer;
    			if (kuhn(i)) ++cnt;
    			else break;
    		}
    	}
    	cout << cnt << '\n';
    }
}