#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pli;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int MaxN = 100000;
const int Magic = 316, S = MaxN / Magic + 1;

int n;
int a[100010];
long long K[100010], B[100010];
int alive[100010];
long long MK[S], MB[S];
vector <int> seq[S];
vector <int> st[S];
int P[S];
long long ans;

void Build(int id) {
	int l = id * Magic, r = min((id + 1) * Magic - 1, n - 1);
	for (int i = l; i <= r; i++) {
		K[i] += MK[id], B[i] += MB[id];
		B[i] += K[i] * a[i], K[i] = 0;
	}
	MK[id] = MB[id] = 0;
	vector <int> &st = :: st[id]; st.clear();
	int lst = -1;
	auto Insert = [&](int i) -> void {
		while (st.size() > 1) {
			int p = st[st.size() - 2], q = st[st.size() - 1]; // (a[p], B[p])
			if ((a[q] - a[p]) * (B[i] - B[p]) - (a[i] - a[p]) * (B[q] - B[p]) < 0) break;
			st.pop_back();
		}
		st.push_back(i);
	};
	for (auto i : seq[id]) {
		if (!alive[i]) continue;
		if (lst == -1) lst = i;
		else {
			if (a[lst] != a[i]) Insert(lst), lst = i;
			else lst = B[lst] < B[i] ? i : lst;
		}
	}
	if (lst != -1) Insert(lst);
	P[id] = 0;
}

long long GetVal(int x) {return MK[x / Magic] * a[x] + B[x] + MB[x / Magic];};

pli GetMax(int id) {
	const vector <int> &st = :: st[id];
	if (!st.size()) return mp(-INF, -1);
	while (P[id] + 1 < st.size() && GetVal(st[P[id]]) <= GetVal(st[P[id] + 1])) P[id]++;
	return mp(GetVal(st[P[id]]), st[P[id]]);
}

pli GetMax() {
	pli ans = mp(-INF, -1);
	// for (int i = 0; i < n; i++) {
	// 	ans = max(ans, mp(GetVal(i), i));
	// }
	// return ans;
	for (int i = 0; i * Magic < n; i++) {
		ans = max(ans, GetMax(i));
	}
	return ans;
}

void Insert(int x) {
	int id = x / Magic;
	for (int i = 0; i < id; i++) {
		MK[i]++;
	}
	int l = id * Magic, r = min((id + 1) * Magic - 1, n - 1);
	for (int i = l; i <= r; i++) {
		if (i < x) K[i]++;
		else if (i == x) alive[i] = 0;
		else B[i] += a[x];
	}
	for (int i = id + 1; i * Magic < n; i++) {
		MB[i] += a[x];
	}
	Build(id);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		alive[i] = 1;
		scanf("%d", &a[i]), K[i] = 1, B[i] = 0;
		seq[i / Magic].push_back(i);
	}
	reverse(a, a + n);
	// cerr << " a:"; for (int i = 0; i < n; i++) cerr << " " << a[i]; cerr << endl;
	for (int i = 0; i * Magic < n; i++) {
		sort(seq[i].begin(), seq[i].end(), [&](int x, int y) -> bool {return a[x] < a[y];});
		Build(i);
	}
	// auto GetDelta = [&](int x) -> long long {return 1ll * (bit0.query(x, n) + 1) * a[x] + bit1.query(x);};
	while (1) {
		pli tmp = GetMax();
		if (tmp.fi < 0) break;
		ans += tmp.fi;
		Insert(tmp.se);
	}
	printf("%lld\n", ans);
	return 0;
}