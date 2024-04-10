// don't use, it's time heuristic

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct P {
	ll x, y;
	void read() { scanf("%lld%lld", &x, &y); }
	void write() const { printf("(%lld,%lld)", x, y); }
	ll operator * (const P & b) const { return x * b.y - y * b.x; }
	P operator + (const P & b) const { return P{x + b.x, y + b.y}; }
	P operator - (const P & b) const { return P{x - b.x, y - b.y}; }
	bool operator < (const P & b) const {
		return make_pair(x, y) < make_pair(b.x, b.y);
	}
	bool operator == (const P & b) const {
		return make_pair(x, y) == make_pair(b.x, b.y); }
	bool underLine(const P & a, const P & b) const {
		return (b - a) * (*this - a) <= 0;
	}
};
long long Z;
int tak_dupsko;
struct Node {
	int a_size, b_size;
	P * a, * b, * first;
	Node * L, * R;
	int size() { return a_size + b_size; }
	void check() {
		assert((L == NULL) == (R == NULL));
		if(L != NULL) {
			assert((a == NULL) == L -> empty());
			assert((b == NULL) == R -> empty());
		}
		if(L == NULL) {
			assert(size() == 0 || size() == 1);
		}
		else assert(size() <= L -> size() + R -> size());
		// puts("ok");
	}
	bool empty() { return size() == 0; }
	bool isLeaf() { return L == NULL; }
	bool nonLeaf() { return !isLeaf(); }
	void act() {
		if(isLeaf()) {
			check();
			return;
		}
		if(L -> size()) first = L -> first;
		else if(R -> size()) first = R -> first;
		else first = NULL;
		if(L -> empty() || R -> empty()) {
			a = L -> first; // maybe NO/NULL
			a_size = L -> size();
			b = R -> first;
			b_size = R -> size();
			check();
			return;
		}
		assert(L -> size() && R -> size());
		a_size = b_size = 1;
		act(L, R); // modifies a_size and b_size
		check();
	}
	private : void act(Node * inter1, Node * inter2) {
		++Z;
		if(inter1 -> size() == 1 && inter2 -> size() == 1) {
			a = inter1 -> first;
			b = inter2 -> first;
			return;
		}
		P * A = inter1 -> a, * B = inter1 -> b;
		P * C = inter2 -> a, * D = inter2 -> b;
		if(inter1 -> size() > 1) {
			if(A == NULL) return act(inter1 -> R, inter2);
			if(B == NULL) return act(inter1 -> L, inter2);
		}
		if(inter2 -> size() > 1) {
			if(C == NULL) return act(inter1, inter2 -> R);
			if(D == NULL) return act(inter1, inter2 -> L);
		}
		auto remA = [&] {
			a_size += inter1 -> a_size;
			a_size -= inter1 -> R -> size() - inter1 -> b_size;
			act(inter1 -> R, inter2);
		};
		auto remB = [&] { return act(inter1 -> L, inter2); };
		auto remC = [&] { return act(inter1, inter2 -> R); };
		auto remD = [&] {
			b_size += inter2 -> b_size;
			b_size -= inter2 -> L -> size() - inter2 -> a_size;
			act(inter1, inter2 -> L);
		};
		if(inter1 -> size() == 1) {
			if(C->underLine(*inter1 -> first, *D)) return remC();
			else return remD();
		}
		if(inter2 -> size() == 1) {
			if(B->underLine(*A, *inter2 -> first)) return remB();
			else return remA();
		}
		if(B->underLine(*A, *C) || B->underLine(*A, *D)
			|| B->underLine(*A, *inter2 -> first))
				return remB();
		if(C->underLine(*B, *D)) return remC();
		int a_memo = a_size, b_memo = b_size;
		remA();
		if(B->underLine(*A, *b)) {
			a_size = a_memo;
			b_size = b_memo;
			assert(++tak_dupsko < 200 * 1000);
			do { // remD(), repeated
				b_size += inter2 -> b_size;
				b_size -= inter2 -> L -> size() - inter2 -> a_size;
				inter2 = inter2 -> L;
			} while(inter2 -> nonLeaf() && inter2 -> b != NULL
				&& (*B - *A) * (*inter2 -> b - *b) < 0
				&& (*A < *B) == (*b < *inter2 -> b)); // does it work for LOWER?
			do {
				inter1 = inter1 -> L; // remB()
			} while(inter1->nonLeaf() && (inter1 -> b == NULL
				|| (inter1 -> a != NULL
				&& inter1 -> b -> underLine(*inter1 -> a, *b))));
			act(inter1, inter2);
		}
	}
	public : long long query(long long mul) {
		auto evaluate = [&] (P p) { return mul * p.x + p.y; };
		if(size() == 1) return evaluate(*first);
		if(L -> empty()) return R -> query(mul);
		if(R -> empty()) return L -> query(mul);
		if(evaluate(*a) > evaluate(*b)) return L -> query(mul);
		else return R -> query(mul);
	}
};

const int UPPER = 0, LOWER = 1;
const int REPS = 1; // change to 2 to also compute LOWER
long long done[1 << 21];
struct Hull {
	vector<Node> tr[2];
	vector<P> all;
	int pot;
	int getID(const P & a, int type) const {
		int tmp = lower_bound(all.begin(), all.end(), a) - all.begin();
		assert(all[tmp] == a); // I didn't get it in the constructor
		return tmp;
	}
	Hull(vector<P> w) {
		sort(w.begin(), w.end());
		w.resize(unique(w.begin(), w.end()) - w.begin());
		all = w;
		pot = 1;
		while(pot < (int) all.size()) pot *= 2;
		for(int rep = 0; rep < REPS; ++rep) {
			vector<Node> & t = tr[rep];
			t.clear();
			t.resize(2 * pot);
			for(int i = 1; i < pot; ++i) {
				t[i].L = & t[2*i];
				t[i].R = & t[2*i+1];
			}
		}
		for(int i = 0; i < (int) all.size(); ++i) todo.push(pot + i);
	}
	priority_queue<int> todo;
	void change(const P & last) {
		for(int type = 0; type < REPS; ++type) {
			int id = getID(last, type);
			P * which_point = & all[id];
			if(type == LOWER) id = (int) all.size() - 1 - id;
			Node & tmp = tr[type][pot+id];
			if(tmp.empty()) {
				tmp.a_size = 1;
				tmp.first = which_point;
			}
			else {
				tmp.a_size = 0;
				tmp.first = NULL;
			}
			todo.push(pot + id);
		}
	}
	void query(long long mul) {
		static long long T = 0;
		++T;
		while(!todo.empty()) {
			int id = todo.top();
			todo.pop();
			if(done[id] == T) continue;
			done[id] = T;
			// printf("%d (%d)\n", id, (int) todo.size());
			tr[0][id].act();
			if(id != 1) todo.push(id / 2);
		}
		todo = priority_queue<int>();
		if(tr[UPPER][1].size() == 0) {
			puts("EMPTY SET");
			return;
		}
		else printf("%lld\n", tr[0][1].query(mul));
	}
};
const int nax = 6e5 + 5;
int type[nax], val[nax];
P p[nax];
int main() {
	int n;
	scanf("%d", &n);
	vector<P> w;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &type[i]);
		if(type[i] == 1) {
			p[i].read();
			w.push_back(p[i]);
		}
		else scanf("%d", &val[i]);
	}
	Hull hull(w);
	map<P, int> m;
	for(int i = 1; i <= n; ++i) {
		if(type[i] == 1) {
			if(m[p[i]]++ == 0) hull.change(p[i]);
		}
		else if(type[i] == 2) {
			if(--m[p[val[i]]] == 0) hull.change(p[val[i]]);
		}
		else {
			assert(type[i] == 3);
			hull.query(val[i]);
		}
	}
	cerr << "dupsko = " << tak_dupsko << "\n";
	cerr << "Z = " << Z << "\n";
}