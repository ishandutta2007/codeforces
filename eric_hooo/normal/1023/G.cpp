#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int EPT = 2090000000;

const int INF = 2100000000;

int n;
vector <pii> G[100010];
vector <pii> mdy[100010];

struct Data {
	map <int, int> *P, *Q;
	int PP, QQ;
	multiset <pii> *S;
	int SS;
	Data() {P = new map <int, int>, Q = new map <int, int>, S = new multiset <pii>, PP = QQ = SS = 0;}
	int size() const {return P->size() + Q->size() + S->size();}
	void del() {delete P, delete Q, delete S;}
	void flush(int x) {
		// cerr << "  flush:" << x << " " << SS << endl;
		int w = erase(x) + erase(x + 1);
		// cerr << "                                           w:" << w << endl;
		if (w > 0) insert(x + 1, w);
		else insert(x, w);
	}
	void addSS(int lim) {
		lim += SS;
		// cerr << "        addSS:" << lim << endl;
		while (S->size() && S->begin()->fi <= lim) {
			int delta = S->begin()->fi - SS - 1;
			PP -= delta, QQ += delta, SS += delta;
			while (S->begin()->fi == SS + 1) flush(S->begin()->se);
			// int x = S->begin()->se;
			// cerr << "               delta:" << delta << " " << x << endl;
			// flush(x);
			// cerr << "         QWQ" << endl;
		}
		int delta = lim - SS;
		PP -= delta, QQ += delta, SS += delta;
	}
	int val(int x) {return P->count(x - PP) ? P->operator [](x - PP) : Q->count(x - QQ) ? Q->operator [](x - QQ) : 0;}
	int sgn(int x) {return P->count(x - PP) ? 1 : Q->count(x - QQ) ? -1 : 0;}
	void disable(int x, int y) {
		if (x == EPT || y == EPT) return ;
		if (x > y) swap(x, y);
		// cerr << "    dis:" << x << " " << y << endl;
		if (sgn(x) == -1 && sgn(y) == 1) S->erase(S->find(mp(SS + 1 + abs(x - y) / 2, x + y >> 1)));
		// cerr << "                good" << endl;
	}
	void enable(int x, int y) {
		if (x == EPT || y == EPT) return ;
		if (x > y) swap(x, y);
		// cerr << "                                en:" << x << " " << y << endl;
		if (sgn(x) == -1 && sgn(y) == 1) S->insert(mp(SS + 1 + abs(x - y) / 2, x + y >> 1));
	}
	int GetSuc(int x) {
		auto it = P->lower_bound(x + 1 - PP), jt = Q->lower_bound(x + 1 - QQ);
		if (it == P->end() && jt == Q->end()) return EPT;
		if (it == P->end()) return jt->fi + QQ;
		if (jt == Q->end()) return it->fi + PP;
		return min(it->fi + PP, jt->fi + QQ);
	}
	int GetPre(int x) {
		auto it = P->lower_bound(x - PP), jt = Q->lower_bound(x - QQ);
		if (it == P->begin() && jt == Q->begin()) return EPT;
		if (it == P->begin()) return (--jt)->fi + QQ;
		if (jt == Q->begin()) return (--it)->fi + PP;
		return max((--it)->fi + PP, (--jt)->fi + QQ);
	}
	int erase(int x) {
		// cerr << "erase:" << x << endl;
		if (!P->count(x - PP) && !Q->count(x - QQ)) return 0;
		disable(x, GetSuc(x)), disable(x, GetPre(x)), enable(GetPre(x), GetSuc(x));
		// cerr << "qwq:" << endl;
		int val = P->count(x - PP) ? P->operator [](x - PP) : Q->operator [](x - QQ);
		P->erase(x - PP), Q->erase(x - QQ);
		// cerr << "              val:" << val << endl;
		return val;
	}
	void insert(int x, int w) {
		if (w == 0) return ;
		// cerr << "                                               insert:" << x << " " << w << endl;
		(w > 0 ? P->operator [](x - PP) : Q->operator [](x - QQ)) = w;
		enable(x, GetSuc(x)), enable(x, GetPre(x));
		// cerr << "                           ok?" << endl;
		disable(GetPre(x), GetSuc(x));
	}
	void modify(int x, int w) {
		// cerr << "modify:" << x << " " << w << endl;
		w += erase(x);
		// cerr << "mid" << endl;
		insert(x, w);
		// cerr << "end:" << endl;
	}
	void add(int l, int r, int w) {
		modify(l, w), modify(r + 1, -w);
	}
	void apply(int w, vector <pii> &a) {
		// cerr << "          QWQ" << endl;
		sort(a.begin(), a.end());
		static vector <pii> mdy;
		mdy.clear();
		auto it = a.begin();
		// cerr << "      a:" << a.size() << endl;
		while (it != a.end()) {
			auto jt = it; int maxj = it->se; while (jt != a.end() && it->fi == jt->fi) maxj = max(maxj, jt->se), jt++;
			// cerr << "                                               it:" << it->fi << " : " << maxj << endl;
			mdy.push_back(mp(it->fi, max(0, maxj - max(0, max(-val(it->fi), val(it->fi + 1)))))), it = jt;	
		}
		// cerr << "         EQ" << endl;
		addSS(1);
		for (auto it : mdy) {
			// cerr << "                                                              old:" << it.fi << " " << it.se << endl;
			add(it.fi, it.fi, it.se);
		}
		// cerr << "       getmaxj:" << getmaxj() << endl;
		addSS(w - 1);
		// cerr << "  PPP:"; for (auto it : *P) cerr << "  " << it.fi + PP << "," << it.se; cerr << endl;
		// cerr << "  QQQ:"; for (auto it : *Q) cerr << "  " << it.fi + QQ << "," << it.se; cerr << endl;
		// cerr << "                                                         maxj:" << getmaxj() << endl;
	}
	void merge(Data A) {
		for (auto it = A.P->begin(); it != A.P->end(); it++) {
			modify(it->fi + A.PP, it->se);
		}
		for (auto it = A.Q->begin(); it != A.Q->end(); it++) {
			modify(it->fi + A.QQ, it->se);
		}
		A.del();
	}
	int getmaxj() {
		int x = -INF, sum = 0, maxj = 0;
		while (GetSuc(x) != EPT) {
			x = GetSuc(x), sum += P->count(x - PP) ? P->operator [](x - PP) : Q->operator [](x - QQ);
			maxj = max(maxj, sum);
		}
		return maxj;
	}
};

Data dfs(int x, int last) {
	Data rt;
	for (auto it : G[x]) {
		int v = it.fi, w = it.se;
		if (v == last) continue;
		Data tmp = dfs(v, x);
		tmp.apply(w, mdy[v]);
		// cerr << "   dfs:" << v << endl;
		// cerr << "       P:"; for (auto it : *tmp.P) cerr << "  " << it.fi + tmp.PP << "," << it.se; cerr << endl;
		// cerr << "       Q:"; for (auto it : *tmp.Q) cerr << "  " << it.fi + tmp.QQ << "," << it.se; cerr << endl;
		if (tmp.size() > rt.size()) swap(tmp, rt);
		rt.merge(tmp);
	}
	return rt;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w), w *= 2;
		G[x].push_back(mp(y, w)), G[y].push_back(mp(x, w));
	}
	int k; scanf("%d", &k);
	while (k--) {
		int d, f, p; scanf("%d%d%d", &d, &f, &p), d *= 2;
		mdy[p].push_back(mp(d, f));
	}
	Data tmp = dfs(1, 1);
	// cerr << "  POS" << endl;
	// cerr << "       P:"; for (auto it : *tmp.P) cerr << "  " << it.fi + tmp.PP << "," << it.se; cerr << endl;
	// cerr << "       Q:"; for (auto it : *tmp.Q) cerr << "  " << it.fi + tmp.QQ << "," << it.se; cerr << endl;
	// return 0;
	tmp.apply(2, mdy[1]);
	printf("%d\n", tmp.getmaxj());
	return 0;
}