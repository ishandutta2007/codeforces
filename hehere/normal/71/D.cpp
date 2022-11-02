#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 17 + 5;
const set<char> ranks = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
const set<char> suits = {'C', 'D', 'H', 'S'};
struct Card {
	char rk, st;
	Card() {}
	Card(int rk, int st) : rk(rk), st(st) {}
	friend bool operator < (const Card &A, const Card &B) {
		return A.rk != B.rk ? A.rk < B.rk : A.st < B.st;
	}
}a[maxN][maxN], t[maxN][maxN];
struct Point {
	int x, y;
	Point() {}
	Point(int x, int y) : x(x), y(y) {}
}joker[3];
vector<Point> empty;
set<Card> cards;
int n, m;
int jks = 0;
char words[1000];

void initialize() {
	for(char x : ranks) {
		for(char y : suits) {
			cards.insert(Card(x, y));
		}
	}
	cin >> n >> m;
	memset(joker, 0, sizeof(joker));
	empty.clear();
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			char s[10];
			cin >> s;
			if(suits.count(s[1])) {
				t[i][j] = a[i][j] = (Card){s[0], s[1]};
				cards.erase(Card(s[0], s[1]));
			} else {
				joker[s[1] - '0'] = (Point){i, j};
				jks |= (s[1] - '0');
				if(s[1] == '2') empty.push_back(Point(i, j));
				else empty.insert(empty.begin(), Point(i, j));
			}
		}
}

bool ok(int x, int y) {
	set<char> rk, st;
	rk.clear(); st.clear();
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			rk.insert(t[x + i][y + j].rk);
			st.insert(t[x + i][y + j].st);
		}
	}
	if(rk.size() == 9 || st.size() == 1) return true;
	else return false;
}

bool try_sol() {
	for(int x1 = 1; x1 + 2 <= n; ++x1) {
		for(int y1 = 1; y1 + 2 <= m; ++y1) if(ok(x1, y1)) {
//			printf("(%d, %d) passed\n", x1, y1);
			for(int x2 = 1; x2 + 2 <= n; ++x2) {
				for(int y2 = 1; y2 + 2 <= m; ++y2) if(ok(x2, y2)) {
					if(!(std::min(x1, x2) + 2 >= std::max(x1, x2) &&
						std::min(y1, y2) + 2 >= std::max(y1, y2))) {
							printf("Solution exists.\n");
							printf("%s\n", words);
							printf("Put the first square to (%d, %d).\n", x1, y1);
							printf("Put the second square to (%d, %d).\n", x2, y2);
							return true;
						}
				}
			}
		}
	}
	return false;
}

bool solve() {
	assert(__builtin_popcount(jks) == (int)empty.size());
	if(empty.size() == 0) {
		sprintf(words, "There are no jokers.");
		return try_sol();
	}
	else if(empty.size() == 1) {
		int id = -1;
		if(jks == 1) id = 1;
		else id = 2;
		for(Card c : cards) {
			sprintf(words, "Replace J%d with %c%c.", id, c.rk, c.st);
			t[empty[0].x][empty[0].y] = c;
			if(try_sol()) return true;
		}
	} else {
		for(auto i = cards.begin(); i != cards.end(); ++i) {
			for(auto j = cards.begin(); j != cards.end(); ++j) if(i != j) {
				sprintf(words,
					"Replace J1 with %c%c and J2 with %c%c.", i->rk, i->st, j->rk, j->st);
				t[empty[0].x][empty[0].y] = *i;
				t[empty[1].x][empty[1].y] = *j;
				if(try_sol()) return true;
			}
		}
	}
	return false;
}

int main() {
	initialize();
	if(!solve()) {
		printf("No solution.\n");
	}
	return 0;
}