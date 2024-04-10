#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int L = 22;
const int N = 1 << L;

char used[N];
int color[N];
int cur_color = 0;

int inTime[N];
int minInTime[N];
int cur_time = 0;
int st[N];

vector<int> cur;

void dfs(int v);

void trans(int v, int x) {
	if (inTime[x] == -1) {
		dfs(x);
		minInTime[v] = min(minInTime[v], minInTime[x]);
	} else if (st[x] == 1) {
		minInTime[v] = min(minInTime[v], inTime[x]);
	}
}

void dfs(int v) {
	st[v] = 1;
	minInTime[v] = inTime[v] = cur_time++;
	cur.push_back(v);
	for (int i = 1; i <= v; i *= 2) {
		if (v & i) {
			trans(v, v ^ i);
		}
	}
	if (used[v]) {
		trans(v, N - v - 1);
	}
	if (minInTime[v] == inTime[v]) {
		int w;
		do {
			w = cur.back();
			cur.pop_back();
			color[w] = cur_color;
			st[w] = 2;
		} while (w != v);
		++cur_color;
	}
}

int main() {
	[[maybe_unused]]int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		used[nxt()] = 1;
	}

	memset(color, -1, sizeof(color));
	memset(inTime, -1, sizeof(inTime));
	for (int i = 0; i < N; ++i) {
		if (color[i] > -1) {
			continue;
		}
		dfs(i);
	}

	set<int> S;
	for (int i = 0; i < N; ++i) {
		if (used[i]) {
			S.insert(color[N - 1 - i]);
		}
	}

	cout << S.size() << "\n";

	return 0;
}