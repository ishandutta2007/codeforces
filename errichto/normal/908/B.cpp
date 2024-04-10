#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int nax = 105;
string in[nax];
string moves;
bool block[nax][nax];
int h, w;

bool inside(int row, int col) {
	return 0 <= row && row < h && 0 <= col && col < w;
}

bool okk(int row, int col) {
	return inside(row, col) && !block[row][col];
}

pair<int,int> start, end2;

int main() {
	cin >> h >> w;
	for(int row = 0; row < h; ++row) {
		cin >> in[row];
		for(int col = 0; col < w; ++col) {
			if(in[row][col] == '#') block[row][col] = true;
			if(in[row][col] == 'S') start = {row, col};
			if(in[row][col] == 'E') end2 = {row, col};
		}
	}
	cin >> moves;
	vector<pair<int,int>> dir{ {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	sort(dir.begin(), dir.end());
	int answer = 0;
	do {
		int row = start.first;
		int col = start.second;
		bool ok = true;
		for(char ch : moves) {
			int dx = dir[ch - '0'].first;
			int dy = dir[ch - '0'].second;
			row += dx;
			col += dy;
			if(!okk(row, col)) {
				ok = false;
				break;
			}
			if(end2 == make_pair(row, col)) break;
		}
		if(ok && end2 == make_pair(row, col)) ++answer;
	} while(next_permutation(dir.begin(), dir.end()));
	printf("%d\n", answer);
}