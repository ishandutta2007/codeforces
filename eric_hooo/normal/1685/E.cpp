#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii operator * (const pii &A, const pii &B) {
	return mp(A.fi + B.fi, A.se + B.se);
}

int n;

const int INF = 0x3f3f3f3f;

template <typename T>
int LIS(T a, int L = -INF, int R = INF) {
	vector <int> f;
	for (auto x : a) if (L <= x && x <= R) {
		auto it = lower_bound(f.begin(), f.end(), x);
		if (it == f.end()) f.push_back(x);
		else *it = x;
	}
	return f.size();
}

struct Data {
	int sz;
	int sum;
	pii pre_min;
	Data() {sz = 0, sum = 0, pre_min = mp(0, 0);}
	Data(int x) {sz = 1, sum = x, pre_min = min(mp(0, 0), mp(x, 1));}
};

Data operator + (const Data &A, const Data &B) {
	Data res;
	res.sz = A.sz + B.sz;
	res.sum = A.sum + B.sum;
	res.pre_min = min(A.pre_min, B.pre_min * mp(A.sum, A.sz));
	return res;
}

struct Node {
	int x;
	Data sum;
	int fix;
	Node *lson, *rson;
	void init(int X) {x = X, fix = (unsigned)rand() << 15 ^ rand(), lson = rson = NULL, pushup();}
	Data lsum() const {return lson ? lson->sum : Data();}
	Data mysum() const {return Data(x <= n ? -1 : x == n + 1 ? 0 : 1);}
	Data rsum() const {return rson ? rson->sum : Data();}
	void pushup() {
		sum = lsum() + mysum() + rsum();
	}
}POOL[200010];

typedef pair <Node *, Node *> pnn;

Node *Merge(Node *L, Node *R) {
	if (!L || !R) return L ? L : R;
	if (L->fix > R->fix) {
		L->rson = Merge(L->rson, R);
		L->pushup();
		return L;
	} else {
		R->lson = Merge(L, R->lson);
		R->pushup();
		return R;
	}
}

template <typename ...Args>
Node *Merge(Node *L, Node *R, Args ...args) {
	return Merge(Merge(L, R), args...);
}

pnn Split(Node *T, int k) {
	if (!T) return pnn(NULL, NULL);
	if (k <= T->lsum().sz) {
		pnn t = Split(T->lson, k);
		T->lson = t.se, T->pushup();
		return mp(t.fi, T);
	} else {
		pnn t = Split(T->rson, k - T->lsum().sz - T->mysum().sz);
		T->rson = t.fi, T->pushup();
		return mp(T, t.se);
	}
}

void Print(Node *T, string s = "") {
	if (!T) {
		printf("%s", s.c_str());
		return ;
	}
	Print(T->lson), printf("%d ", T->x), Print(T->rson), printf("%s", s.c_str());
}

int main() {
	srand((int)time(NULL) ^ (unsigned long long)(new char));
	// srand(114);
	// {
	// 	int n = 4;
	// 	deque <int> a;
	// 	for (int i = 0; i < n + n + 1; i++) {
	// 		a.push_back(i);
	// 	}
	// 	do {
	// 		int ok = 1, maxj = 0, PRT = vector <int>(a.begin(), a.begin() + 3) == vector <int>{0, 2, 1};
	// 		for (int i = 0; i < a.size(); i++) {
	// 			int len = LIS(a);
	// 			maxj = max(maxj, len);
	// 			// minj = min(minj, len);
	// 			// if (PRT && a[4] == 0) {
	// 			// 		cerr << " -:"; for (auto it : a) cerr << " " << it; cerr << endl;
	// 			// 	cerr << "    len:" << len << endl;
	// 			// 	assert(len <= n);
	// 			// }
	// 			if (len <= n) {
	// 				if (ok && PRT) {
	// 					// cerr << " a:"; for (auto it : a) cerr << " " << it; cerr << endl;
	// 				}
	// 				ok = 0;
	// 				// cerr << "            a:"; for (auto it : a) cerr << " " << it; cerr << endl;
	// 				// cerr << "            LIS:" << LIS(a) << endl;
	// 			}
	// 			a.push_back(a[0]), a.pop_front();
	// 		}
	// 		if (ok) {
	// 			cerr << "     minj:" << minj << " " << maxj << endl;
	// 		}
	// 		{
	// 			int leq = 0;
	// 			for (int i = 0; i < a.size(); i++) {
	// 				leq += a[i] < a[(i + 1) % a.size()];
	// 			}
	// 			if (leq <= n) {
	// 				assert(!ok);
	// 				continue;
	// 			}
	// 		}
	// 		// cerr << "  a:"; for (auto it : a) cerr << " " << it; cerr << endl;
	// 		// if (ok && maxj == 6) cerr << "                                        maxj:" << maxj << endl;
	// 		int my = 1, minj = 0x3f3f3f3f, to = 0x3f3f3f3f;
	// 		for (int i = 0; i < a.size(); i++) {
	// 			int real = LIS(a);
	// 			for (int j = 0; j < a.size(); j++) {
	// 				if (a[j] == 4) {
	// 					int len = LIS(vector <int>(a.begin(), a.begin() + j), -INF, a[j] - 1) + 1
	// 							+ LIS(vector <int>(a.begin() + j + 1, a.end()), a[j] + 1, INF);
	// 					if (len < minj) minj = len, to = 0x3f3f3f3f;
	// 					if (len == minj) to = min(to, real);
	// 					if (len <= n) my = 0;
	// 					// cerr << "    real:" << (real <= n) << " " << (len <= n) << endl;
	// 					assert(len <= real);
	// 					// assert((real <= n) == (len <= n));
	// 					break;
	// 				}
	// 			}
	// 			// if (LIS(a, -INF, a[0] - 1) + 1 + LIS(a, a[0] + 1, INF) <= n) my = 0;
	// 			a.push_back(a[0]), a.pop_front();
	// 		}
	// 		// cerr << "a:"; for (auto it : a) cerr << " " << it; cerr << endl;
	// 		// cerr << "       ok:" << ok << " " << my << endl;
	// 		if (ok == 1) {
	// 			cerr << " ok:" << ok << " : " << minj << " : " << to << " : "; for (auto it : a) cerr << " " << it; cerr << endl;
	// 		} else {
	// 			// cerr << "    minj:" << (minj <= n) << " " << (to <= n) << endl;
	// 		}
	// 	} while (next_permutation(a.begin(), a.end()));
	// 	return 0;
	// }
	int q; scanf("%d%d", &n, &q);
	static int a[200010], p[200010];
	Node *T = NULL;
	for (int i = 1; i <= n + n + 1; i++) {
		scanf("%d", &a[i]), p[a[i]] = i;
		POOL[i].init(a[i]);
		T = Merge(T, POOL + i);
	}
	int Lef = 0, Rig = 0;
	auto Dist = [&](int x, int y) -> int {return p[x] < p[y] ? p[y] - p[x] : p[y] + n + n + 1 - p[x];};
	auto _Modify = [&](int x, int coef) -> void {
		(x < n + 1 ? Lef : Rig) += Dist(x, x + 1) * coef;
	};
	auto Modify = [&](int x, int coef) -> void {
		if (x > 1) _Modify(x - 1, coef);
		if (x < n + n + 1) _Modify(x, coef);
	};
	Lef += Dist(n + 1, 1), Rig += Dist(n + n + 1, n + 1);
	for (int i = 1; i < n + n + 1; i++) {
		_Modify(i, 1);
	}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		if (x > y) swap(x, y);
		{
			Lef -= Dist(n + 1, 1), Rig -= Dist(n + n + 1, n + 1);
			int u = a[x], v = a[y], s = p[u], t = p[v];
			Modify(u, -1), p[u] = t, Modify(u, 1);
			Modify(v, -1), p[v] = s, Modify(v, 1);
			Lef += Dist(n + 1, 1), Rig += Dist(n + n + 1, n + 1);
			swap(a[x], a[y]);
		}
		{
			pnn t1 = Split(T, x - 1), t2 = Split(t1.se, 1), t3 = Split(t2.se, y - x - 1), t4 = Split(t3.se, 1);
			// cerr << " t1:"; Print(t1.fi, "\n");
			// cerr << " t2:"; Print(t2.fi, "\n");
			// cerr << " t3:"; Print(t3.fi, "\n");
			// cerr << " t4:"; Print(t4.fi, "\n");
			// cerr << " t4:"; Print(t4.se, "\n");
			T = Merge(t1.fi, t4.fi, t3.fi, t2.fi, t4.se);
			// cerr << "  T:"; Print(T, "\n");
		}
		int ans = -1;
		{
			int pos = p[n + 1];
			pnn t1 = Split(T, pos - 1), t2 = Split(t1.se, 1);
			Node *tmp = Merge(t2.se, t1.fi);
			if (tmp->sum.pre_min.fi < 0) ans = (pos + tmp->sum.pre_min.se) % (n + n + 1);
			pnn tt = Split(tmp, n + n + 1 - pos);
			T = Merge(tt.se, t2.fi, tt.fi);
		}
		if (ans == -1) {
			if (Lef != n + n + 1) ans = p[n + 1] % (n + n + 1);
		}
		if (ans == -1) {
			if (Rig != n + n + 1) ans = p[n + 1] - 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}