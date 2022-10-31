#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int N = 1e5 + 100;

string s[N];

struct Block {
	vector<string> s;
	bool lockedAfter[2];
	int ansPos[2];
	
	void append(string &t) {
		s.pb(t);
	}
	
	void update(int pos, string &t) {
		s[pos] = t;
		recalc();
	}
	
	void recalc() {
		lockedAfter[0] = false;
		lockedAfter[1] = true;
		ansPos[0] = ansPos[1] = -1;
		forn(pos, sz(s)) {
			if (s[pos] == "lock") {
				lockedAfter[0] = lockedAfter[1] = true;
			} else if (s[pos] == "unlock") {
				lockedAfter[0] = lockedAfter[1] = false;
			} else {
				forn(i, 2) {
					if (!lockedAfter[i]) {
						ansPos[i] = pos;
					}
				}
			}
		}
	}
	
	bool isLocked(bool lockedBefore) const {
		return lockedAfter[lockedBefore];
	}
	
	bool gotUpdate(bool lockedBefore) const {
		return ansPos[lockedBefore] != -1;
	}
	
	string& ans(bool lockedBefore) {
		return s[ansPos[lockedBefore]];
	}
};

void showAns(vector<Block> &blocks) {
	string ans = "blue";
	bool lockedBefore = false;
	for(auto &block : blocks) {
		if (block.gotUpdate(lockedBefore)) {
			ans = block.ans(lockedBefore);
		}
		lockedBefore = block.isLocked(lockedBefore);
	}
	cout << ans << '\n';
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int blockSize = 300;
	vector<Block> blocks;
	forn(i, n) {
		if (i % blockSize == 0) {
			blocks.pb(Block());
		}
		string t;
		cin >> t;
		blocks.back().append(t);
	}
	for(auto &block : blocks) {
		block.recalc();
	}
	showAns(blocks);
	int q;
	cin >> q;
	forn(i, q) {
		int pos;
		string t;
		cin >> pos >> t;
		pos--;
		blocks[pos / blockSize].update(pos % blockSize, t);
		showAns(blocks);
	}
	return 0;
}