#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif

	//srand(time(NULL));
}

const int N = 4e5 + 228;

int t[N * 4];
int mod[N * 4];
pair<int, int> who[N];

vector<int> g[N];
vector<int> tin;
int time = 0;

void dfs(int v, vector<int> &used) {
	used[v] = 1;
	who[v].first = time++;
	for(auto i: g[v]) {
		if (!used[i])
			dfs(i, used);
	}
	who[v].second = time;
}

void push(int v, int l, int r) {
	mod[v] = mod[v] % 2;
	if (mod[v] == 1) {
		mod[v * 2] += 1;
		mod[v * 2 + 1] += 1;
		t[v] = r - l - t[v];
	}
	mod[v] = 0;
}

void build(int v, int l, int r, vector<int> &a) {
	if (r - l == 1) {
		t[v] = a[l];
		return;
	}
	int m = (l + r) / 2;
	build(v * 2 + 1, l, m, a);
	build(v * 2, m, r, a);
	t[v] = t[v * 2 + 1] + t[v * 2];
}

void update(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (L >= r || R <= l)
        return;

	if (R >= r && L <= l) {
		mod[v] += 1;
		push(v, l, r);
		return;
	}

	int m = (l + r) / 2;
	update(v * 2 + 1, l, m, L, R);
	update(v * 2, m, r, L, R);
	t[v] = t[v * 2 + 1] + t[v * 2];
}

int get(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (L >= r || R <= l)
        return 0;

    if (R >= r && L <= l)
		return t[v];

	int m = (l + r) / 2;
	return get(v * 2 + 1, l, m, L, R) + get(v * 2, m, r, L, R);
}

signed main() {
   	setup();
   	fill_n(mod, N * 4, 0);

	int n;
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int a;
		cin >> a;
		g[a - 1].push_back(i);
		g[i].push_back(a - 1);
	}
	vector<int> used(n);
	dfs(0, used);
	vector<int> p(n);
	for(int i = 0; i < n; ++i) 
		cin >> p[who[i].first];
	build(1, 0, n, p);


	int k;
	cin >> k;
	for(int i = 0; i < k; ++i) {
		string s;
		int z;
		cin >> s >> z;
		--z;
		if (s == "get") {
			cout << get(1, 0, n, who[z].first, who[z].second) << '\n';
		}
		else {
			update(1, 0, n, who[z].first, who[z].second);
		}
	}
}