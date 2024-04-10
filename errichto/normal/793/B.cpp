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

const int nax = 1005;
int h, w;
char sl[nax][nax];
bool old[nax][nax], tmp[nax][nax], nowy[nax][nax];
bool ok[nax][nax];

void push() {
	for(int row = 0; row < h; ++row)
		for(int col = 0; col < w; ++col) {
			if(!ok[row][col]) tmp[row][col] = false;
			if(old[row][col]) tmp[row][col] = true;
			if(tmp[row][col]) {
				if(row != h - 1) tmp[row+1][col] = true;
				nowy[row][col] = true;
			}
			tmp[row][col] = false;
		}
	for(int row = 0; row < h; ++row)
		for(int col = 0; col < w; ++col) {
			if(!ok[row][col]) tmp[row][col] = false;
			if(old[row][col]) tmp[row][col] = true;
			if(tmp[row][col]) {
				if(col != w - 1) tmp[row][col+1] = true;
				nowy[row][col] = true;
			}
			tmp[row][col] = false;
		}
	for(int row = h - 1; row >= 0; --row)
		for(int col = w - 1; col >= 0; --col) {
			if(!ok[row][col]) tmp[row][col] = false;
			if(old[row][col]) tmp[row][col] = true;
			if(tmp[row][col]) {
				if(row) tmp[row-1][col] = true;
				nowy[row][col] = true;
			}
			tmp[row][col] = false;
		}
	for(int row = h - 1; row >= 0; --row)
		for(int col = w - 1; col >= 0; --col) {
			if(!ok[row][col]) tmp[row][col] = false;
			if(old[row][col]) tmp[row][col] = true;
			if(tmp[row][col]) {
				if(col) tmp[row][col-1] = true;
				nowy[row][col] = true;
			}
			tmp[row][col] = false;
		}
	for(int row = 0; row < h; ++row)
		for(int col = 0; col < w; ++col) {
			if(!ok[row][col]) tmp[row][col] = false;
			old[row][col] = nowy[row][col];
			nowy[row][col] = false;
		}
}

int main() {
	scanf("%d%d", &h, &w);
	for(int row = 0; row < h; ++row) {
		scanf("%s", sl[row]);
		for(int col = 0; col < w; ++col) {
			ok[row][col] = sl[row][col] != '*';
			if(sl[row][col] == 'S')
				old[row][col] = true;
		}
	}
	for(int repeat = 0; repeat < 3; ++repeat)
		push();
	for(int row = 0; row < h; ++row)
		for(int col = 0; col < w; ++col)
			if(sl[row][col] == 'T')
				puts(old[row][col] ? "YES" : "NO");
}