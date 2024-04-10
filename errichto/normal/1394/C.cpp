#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

pair<int,int> read() {
	static char s[500123];
	scanf("%s", s);
	int a = 0, b = 0;
	int len = strlen(s);
	for(int i = 0; i < len; ++i) {
		if(s[i] == 'B') {
			a++;
		}
		else {
			b++;
		}
	}
	return {a, b};
}

const int INF = 1e9 + 5;

void maxi(int& a, int b) {
	a = max(a, b);
}
void mini(int& a, int b) {
	a = min(a, b);
}

bool order(int a, int b, int c) {
	return a >= b && b >= c;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> in(n);
	for(int i = 0; i < n; ++i) {
		in[i] = read();
	}
	int max_y = -INF;
	int min_y = INF;
	int max_x = -INF;
	int min_x = INF;
	int max_xy = -INF;
	int min_xy = INF;
	for(pair<int,int> p : in) {
		int x = p.first;
		int y = p.second;
		maxi(max_y, y);
		mini(min_y, y);
		maxi(max_x, x);
		mini(min_x, x);
		maxi(max_xy, x - y);
		mini(min_xy, x - y);
	}
	int low = 0, high = 1e6 + 5;
	pair<int, pair<int,int>> answer{-1, {-1,-1}};
	debug() << imie(min_x) imie(max_x) imie(min_y) imie(max_y) imie(min_xy) imie(max_xy);
	while(low <= high) {
		int mid = (low + high) / 2;
		min_x += mid;
		min_y += mid;
		max_x -= mid;
		max_y -= mid;
		max_xy -= mid;
		min_xy += mid;
		
		bool ok = false;
		if(min_x >= max_x && min_y >= max_y && min_xy >= max_xy) {
			vector<pair<int,int>> cands;
			for(int x : {min_x, max_x, 0}) {
				for(int y : {min_y, max_y, 0}) {
					cands.emplace_back(x, y);
				}
			}
			for(int x : {min_x, max_x, 0}) {
				for(int xy : {min_xy, max_xy}) {
					int y = x - xy;
					cands.emplace_back(x, y);
				}
			}
			for(int y : {min_y, max_y, 0}) {
				for(int xy : {min_xy, max_xy}) {
					int x = y + xy;
					cands.emplace_back(x, y);
				}
			}
			cands.emplace_back(1, 0);
			cands.emplace_back(1, 1);
			cands.emplace_back(0, 1);
			for(pair<int,int> p : cands) {
				int x = max(0, p.first);
				int y = max(0, p.second);
				if(x == 0 && y == 0) {
					continue;
				}
				if(order(min_x, x, max_x) && order(min_y, y, max_y) && order(min_xy, x - y, max_xy)) {
					answer = {mid, {x, y}};
					ok = true;
				}
			}
		}
		if(ok) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
		
		mid *= -1;
		min_x += mid;
		min_y += mid;
		max_x -= mid;
		max_y -= mid;
		max_xy -= mid;
		min_xy += mid;
		mid *= -1;
	}
	debug() << imie(answer);
	printf("%d\n", answer.first);
	int x = answer.second.first;
	int y = answer.second.second;
	string s(x, 'B');
	string t(y, 'N');
	printf("%s\n", (s+t).c_str());
}