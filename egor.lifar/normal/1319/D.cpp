#include <bits/stdc++.h>


using namespace std;
template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define left left228
#define right right228
#define rank rank228
#define y1 y1228
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
#define pb push_back
#define mp make_pair
using ll = long long;
using ld = long double;
// const int MAXMEM = 200 * 1000 * 1024;
// char _memory[MAXMEM];
// size_t _ptr = 0;
// void* operator new(size_t _x) { _ptr += _x; return _memory + _ptr - _x; }
// void operator delete (void*) noexcept {}
const string FILENAME = "input";
const int MAXN = 200228;


int n, m;
vector<int> g[MAXN];
int k;
int p[MAXN];
bool used[MAXN];
int dist[MAXN];
vector<int> rg[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		rg[a].pb(b);
		g[b].pb(a);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> p[i];
	}
	queue<int> q;
	q.push(p[k - 1]);
	used[p[k - 1]] = true;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		for (auto h: g[a]) {
			if (!used[h]) {
				dist[h] = dist[a] + 1;
				used[h] = true;
				q.push(h);
			}
		}
	}
	int a = 0, b = 0;
	for (int i =0; i < k - 1; i++) {
		int f = dist[p[i]];
		int kek = 0;
		for (auto h: rg[p[i]]) {
			if (used[h] && dist[h] == f - 1) {
				kek++;
			}
		}
		if (f - 1 == dist[p[i + 1]]) {
			//cout << kek << endl;
			if (kek >= 2) {
				b++;
			}
		} else {
			a++;
			b++;
		}
	}
	cout << a << ' ' << b << '\n';
}