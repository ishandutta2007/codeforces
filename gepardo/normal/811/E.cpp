#include <cstdio>
#include <string>
#include <vector>

using namespace std;

class FastInput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline char getChar() {
			if (*bufPtr == '\0') {
				int bytesRead = fread(buffer, 1, bufSize, f);
				buffer[bytesRead] = '\0';
				bufPtr = buffer;
			}
			if (*bufPtr == '\0') {
				return '\0';
			} else {
				return *(bufPtr++);
			}
		}
		
		inline string getToken() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			string res = "";
			while (c > ' ') {
				res += c;
				c = getChar();
			}
			return res;
		}
		
		inline int getInt() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			int sign = +1;
			if (c == '+' || c == '-') {
				sign = (c == '+') ? +1 : -1;
				c = getChar();
			}
			unsigned int res = 0;
			while ('0' <= c && c <= '9') {
				res *= 10;
				res += c - '0';
				c = getChar();
			}
			return res * sign;
		}
		
		FastInput(FILE* f, bool autoClose = true)
			:  bufPtr(buffer), f(f), autoClose(autoClose) {
			buffer[0] = '\0';
		}
		
		~FastInput() {
			if (autoClose) {
				fclose(f);
			}
		}
};

class FastOutput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline FastOutput& flush() {
			int portion = bufPtr - buffer;
			if (portion == 0) {
				return *this;
			}
			int bytesWritten = fwrite(buffer, 1, portion, f);
			if (bytesWritten != portion) {
				puts("Disk write error!!!");
			}
			bufPtr = buffer;
			return *this;
		}
	
		inline FastOutput& putChar(char c) {
			if (bufPtr == buffer + bufSize) {
				flush();
			}
			*(bufPtr++) = c;
			return *this;
		}
		
		inline FastOutput& putChars(const char* c) {
			while (*c != '\0') {
				putChar(*c);
				c++;
			}
			return *this;
		}
		
		inline FastOutput& putString(const string& s) {
			putChars(s.c_str());
			return *this;
		}
		
		inline FastOutput& putInt(int v) {
			unsigned int n = v;
			if (v < 0) {
				putChar('-');
				n = -n;
			}
			char buf[20] = {}, *pos = buf;
			do {
				*(pos++) = (n % 10) + '0';
				n /= 10;
			} while (n != 0);
			do {
				pos--;
				putChar(*pos);
			} while (pos != buf);
			return *this;
		}
		
		inline FastOutput& putLn() {
			putChar('\n');
			return *this;
		}
		
		FastOutput(FILE* f, bool autoClose = true)
			: bufPtr(buffer), f(f), autoClose(autoClose) {
		}
		
		~FastOutput() {
			flush();
			if (autoClose) {
				fclose(f);
			}
		}
};

FastInput fin(stdin);
FastOutput fout(stdout);

class DisjointSetUnion {
private:
	class ValueKeeper {
	private:
		struct Action {
			enum class Kind {
				PRE,
				SIZE,
				COMPCNT
			};
			
			int cell;
			Kind kind;
			int wasValue;
			
			Action() {
			}
			
			Action(int cell, Kind kind, int wasValue)
				: cell(cell), kind(kind), wasValue(wasValue) {
			}
		};
		
		vector<int> pre;
		vector<int> size;
		int compCnt;
		vector<Action> actions;
		
		inline void unapplyAction(const Action &action) {
			switch (action.kind) {
				case Action::Kind::PRE : { 
					pre[action.cell] = action.wasValue;
				} break;
				case Action::Kind::SIZE : {
					size[action.cell] = action.wasValue;
				} break;
				case Action::Kind::COMPCNT : {
					compCnt = action.wasValue;
				} break;
			}
		}
	public:
		typedef size_t State;
		
		inline State saveState() {
			return actions.size();
		}
		
		inline void undo(State state) {
			while (state != actions.size()) {
				unapplyAction(actions.back());
				actions.pop_back();
			}
		}
		
		inline int getPre(int idx) {
			return pre[idx];
		}
		
		inline void setPre(int idx, int value) {
			actions.emplace_back(idx, Action::Kind::PRE, pre[idx]);
			pre[idx] = value;
		}
		
		inline int getSize(int idx) {
			return size[idx];
		}
		
		inline void setSize(int idx, int value) {
			actions.emplace_back(idx, Action::Kind::SIZE, size[idx]);
			size[idx] = value;
		}
		
		inline int getCompCnt() {
			return compCnt;
		}
		
		inline void setCompCnt(int value) {
			actions.emplace_back(0, Action::Kind::COMPCNT, compCnt);
			compCnt = value;
		}
		
		ValueKeeper(int n)
			: pre(n, -1), size(n, 1), compCnt(n) {
		}
	} keeper;
public:
	typedef ValueKeeper::State State;
	
	inline State saveState() {
		return keeper.saveState();
	}
	
	inline void undo(State state) {
		keeper.undo(state);
	}
	
	inline int parent(int v) {
		if (keeper.getPre(v) < 0) {
			return v;
		} else {
			int val = parent(keeper.getPre(v));
			keeper.setPre(v, val);
			return val;
		}
	}
	
	inline int compCount() {
		return keeper.getCompCnt();
	}
	
	inline void unite(int a, int b) {
		a = parent(a);
		b = parent(b);
		if (a == b) {
			return;
		}
		int aSz = keeper.getSize(a);
		int bSz = keeper.getSize(b);
		if (aSz < bSz) {
			swap(a, b);
			swap(aSz, bSz);
		}
		keeper.setPre(b, a);
		keeper.setSize(a, aSz + bSz);
		keeper.setCompCnt(keeper.getCompCnt() - 1);
	}
	
	DisjointSetUnion(int n)
		: keeper(n) {
	}
};

class SegmentTree {
private:
	int n, m, q;
	vector< vector<int> > &v;
	DisjointSetUnion dsu;
	vector< vector<int> > tree;
	
	void add(int x, int tl, int tr, int l, int r, int who) {
		if (l > r) {
			return;
		}
		if (l == tl && r == tr) {
			tree[x].push_back(who);
			return;
		}
		int tm = (tl + tr) / 2;
		add(x*2, tl, tm, l, min(tm, r), who);
		add(x*2+1, tm+1, tr, max(tm+1, l), r, who);
	}
	
	inline void dsuPush(int who) {
		for (int i = 0; i < n; i++) {
			if (v[i][who] == v[i][who-1]) {
				dsu.unite(i*m + who, i*m + (who-1));
			}
		}
	}
	
	void buildAns(int x, int tl, int tr, vector<int> &v) {
		DisjointSetUnion::State state = dsu.saveState();
		for (int who: tree[x]) {
			dsuPush(who);
		}
		if (tl == tr) {
			v[tl] = dsu.compCount(); 
		} else {
			int tm = (tl + tr) / 2;
			buildAns(x*2, tl, tm, v);
			buildAns(x*2+1, tm+1, tr, v);
		}
		dsu.undo(state);
	}
public:
	inline vector<int> build() {
		vector<int> ans(q);
		buildAns(1, 0, q-1, ans);
		return ans;
	}
	
	inline void add(int l, int r, int who) {
		add(1, 0, q-1, l, r, who);
	}
	
	SegmentTree(int n, int m, int q, vector< vector<int> > &v)
		: n(n), m(m), q(q), v(v), dsu(n * m), tree(4 * q) {
		for (int j = 0; j < m; j++) {
			for (int i = 1; i < n; i++) {
				if (v[i][j] == v[i-1][j]) {
					dsu.unite(i*m + j, (i-1)*m + j);
				}
			}
		}
	}
};

int main() {
	int n = fin.getInt(), m = fin.getInt(), q = fin.getInt();
	vector< vector<int> > v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v[i][j] = fin.getInt();
		}
	}
	vector<int> kompLeft(m), kompRight(m);
	{
		DisjointSetUnion dsuLeft(n * m);
		for (int j = 0; j < m; j++) {
			for (int i = 1; i < n; i++) {
				if (v[i][j] == v[i-1][j]) {
					dsuLeft.unite(i*m + j, (i-1)*m + j);
				}
			}
			if (j != 0) {
				for (int i = 0; i < n; i++) {
					if (v[i][j] == v[i][j-1]) {
						dsuLeft.unite(i*m + j, i*m + (j-1));
					}
				}
			}
			kompLeft[j] = dsuLeft.compCount() - n * (m - j - 1);
		}
	}
	{
		DisjointSetUnion dsuRight(n * m);
		for (int j = m-1; j >= 0; j--) {
			for (int i = 1; i < n; i++) {
				if (v[i][j] == v[i-1][j]) {
					dsuRight.unite(i*m + j, (i-1)*m + j);
				}
			}
			if (j != m-1) {
				for (int i = 0; i < n; i++) {
					if (v[i][j] == v[i][j+1]) {
						dsuRight.unite(i*m + j, i*m + (j+1));
					}
				}
			}
			kompRight[j] = dsuRight.compCount() - n * j;
		}
	}
	SegmentTree segTree(n, m, q, v);
	vector<int> starts(m, 0);
	vector< pair<int, int> > queries(q);
	for (int i = 0; i < q; i++) {
		queries[i].first = fin.getInt();
		queries[i].second = fin.getInt();
		auto add = [&](int who) {
			segTree.add(starts[who], i-1, who);
			starts[who] = i+1;
		};
		if (queries[i].first != 1) {
			add(queries[i].first - 1);
		}
		if (queries[i].second != m) {
			add(queries[i].second);
		}
	}
	for (int i = 1; i < m; i++) {
		segTree.add(starts[i], q-1, i);
	}
	vector<int> ans = segTree.build();
	for (int i = 0; i < q; i++) {
		if (queries[i].first != 1) {
			ans[i] -= kompLeft[queries[i].first - 2];
		}
		if (queries[i].second != m) {
			ans[i] -= kompRight[queries[i].second];
		}
	}
	for (int i = 0; i < q; i++) {
		fout.putInt(ans[i]).putLn();
	}
	return 0;
}