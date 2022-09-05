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

const int nax = 1e5 + 5;
char a[nax], b[nax];

void test_case() {
	int n;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	// vector<int> shift(26, -1);
	vector<vector<bool>> yes(26, vector<bool>(26));
	for(int i = 0; i < n; ++i) {
		int x = a[i] - 'a';
		int y = b[i] - 'a';
		if(x > y) {
			puts("-1");
			return;
		}
		if(x < y) {
			yes[x][y] = true;
		}
	}
	int answer = 0;
	for(int i = 0; i < 26; ++i) {
		for(int j = i + 1; j < 26; ++j) {
			if(yes[i][j]) {
				++answer;
				for(int k = j + 1; k < 26; ++k) {
					if(yes[i][k]) {
						yes[j][k] = true;
					}
				}
				break;
			}
		}
	}
	printf("%d\n", answer);
	/*
		if(shift[x] == y) {
			continue;
		}
		if(shift[x] == -1) {
			shift[x] = y;
		}
		else {
			puts("-1");
			return;
		}
	}
	int answer = 0;
	for(int i = 0; i < 26; ++i) {
		if(shift[i] != -1 && shift[i] != i) {
			++answer;
		}
	}
	printf("%d\n", answer);*/
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}