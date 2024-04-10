#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Pos {
	int x, y;

	Pos() : x(0), y(0) {}
	Pos(int _x, int _y) : x(_x), y(_y) {}

	Pos operator+(const Pos& other) const {
		return Pos(x+other.x, y+other.y);
	}

	Pos operator-(const Pos& other) const {
		return Pos(x-other.x, y-other.y);
	}

	int manhattan() {
		return abs(x)+abs(y);
	}

	bool isValid() {
		return x >= 0 && y >= 0 && x < 8 && y < 8;
	}

	bool isValid(Pos queenPos) {
		return isValid() && x != queenPos.x && y != queenPos.y && x-y != queenPos.x-queenPos.y && x+y != queenPos.x+queenPos.y;
	}

	void print() {
		cout << x+1 << " " << y+1 << endl;
		cout.flush();
	}
};

bool contains(string s, string t) {
	rep(i,0,sz(s)) {
		if (s.substr(i, sz(t)) == t)
			return true;
	}
	return false;
}

void solve() {
	Pos queen(4, 4);
	vector<Pos> possible;
	rep(i,0,8)
	rep(j,0,8) {
		possible.emplace_back(i, j);
	}
	int movesDone = 0;
	while (true) {
		cout << queen.x+1 << " " << queen.y+1 << endl;
		Pos diff;
		string m;
		cin >> m;
		if (m == "Done")
			return;
		if (contains(m, "Right"))
			diff.y = 1;
		if (contains(m, "Left"))
			diff.y = -1;
		if (contains(m, "Down"))
			diff.x = 1;
		if (contains(m, "Up"))
			diff.x = -1;
		vector<Pos> newPossible;
		for (Pos p : possible) {
			Pos q = p + diff;
			if (q.isValid(queen)) {
				newPossible.push_back(q);				
			}
		}
		possible = newPossible;
		cerr << "Possible: ";
		for (auto p : possible) {
			cerr << "(" << (p.x+1) << ", " << (p.y+1) << ") ";
		}
		cerr << endl;
		++movesDone;
		if (movesDone == 129)
			assert(false);
		Pos bestMove;
		int bestScore = -1e9;
		rep(dx,-1,2)
		rep(dy,-1,2) {
			if (dx == 0 && dy == 0)
				continue;
			rep(k,0,8) {
				Pos p(queen.x+k*dx, queen.y+k*dy);
				if (!p.isValid())
					continue;
				int score = 1000-10*(p-possible[0]).manhattan()-(p-Pos(4, 4)).manhattan();
				if (score > bestScore) {
					bestScore = score;
					bestMove = p;
				}
			}
		}
		queen = bestMove;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
}