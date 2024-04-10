#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;

vector<int> pri, op, ans;
vector<P> fac[maxn];
vector<int> p[maxn * 10];
multiset<P> lv;
P sum[maxn * 10];
int a[maxn], b[maxn], vis[maxn * 10];

void work(vector<int> &f) {
	int m = f.size(), r, t = 0;
	for (int i = 1; i < (1 << m); i++) t += abs(__builtin_popcount(i) - 2);
	cout << t << endl;
	for (int i = 1; i < (1 << m); i++) {
		vector<int> d;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) d.push_back(f[j]);
		}
		r = d.size();
		if (r & 1) r = -(r - 2);
		else r = r - 2;
		if (r < 0) {
			for (int k = 0; k < (-r); k++) {
				cout << 1 << " " << d.size();
				for (auto e:d) cout << " " << e;
				cout << endl;
			}
		} else {
			for (int k = 0; k < r; k++) {
				cout << 0 << " " << d.size();
				for (auto e:d) cout << " " << e;
				cout << endl;
			}
		}
	}
}

void solve()
{
	auto tryMove = [&](P u) {
		auto e = lv.find(u);
		if (e != lv.end()) {
			lv.erase(e);
			return true;
		}
		return false;
	};

	for (int i = 2; i <= 1000; i++) {
		if (a[i]) continue;
		pri.push_back(i);
		for (int j = i + i; j <= 1000; j += i) a[j] = 1;
	}

	int n, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = x;
		for (auto e:pri) {
			if (x % e) continue;
			int t = 0;
			while(x % e == 0) x /= e, t++;
			fac[i].push_back(P(e, t));
			if (x == 1) break;
		}
		if (x > 1) fac[i].push_back(P(x, 1));

		for (auto e:fac[i]) p[e.fi].push_back(e.se);
	}

	for (int i = 2; i <= 1000000; i++) {
		if (!p[i].size()) continue;
		op.push_back(i);
		sort(p[i].begin(), p[i].end());
	}


	for (int i = 1; i <= n; i++) b[i] = i;
	sort(b + 1, b + n + 1, [&](int xx, int yy) {
        return a[xx] < a[yy];
      });
	for (auto e:op) {
        P u;
		if (p[e].size() <= n - 2) u = P(0, 0);
		else if (p[e].size() == n - 1) u = P(0, p[e][0]);
		else u = P(p[e][0], p[e][1]);
        lv.insert(P(e, u.fi));
        lv.insert(P(e, u.se));
	}

	for (int j = 1; j <= n && !lv.empty(); j++) {
        int i = b[j];
		x = 0;

		for (auto e:lv) {
            if (a[i] % e.fi != 0 && e.se == 0 && vis[e.fi] != i) {
                fac[i].push_back(e);
                vis[e.fi] = i;
            }
		}

		for (auto e:fac[i]) x |= tryMove(e);
		if (x) ans.push_back(i);
	}

	sort(ans.begin(), ans.end());
	work(ans);
}

int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}