#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

struct shit{
	int l, r;
	int L, R;

	shit(int l = 0, int r = 0, int L = 0, int R = 0):l(l),r(r),L(L),R(R){}

	bool operator <(const shit& x) const {
		return r < x.l;
	}
};

int main(){

	int n = nxt(), q = nxt();
	set<shit> S;
	S.insert(shit(1, n, 0, 0));
	while (q--){
		int x = nxt(), y = nxt();
		char c;
		scanf(" %c", &c);
		shit p(x, x);
		auto it = S.lower_bound(p);
		if (it != S.end() && it->l <= x && it->r >= x){
			auto s = *it;
			S.erase(it);
			if (c == 'U'){
				printf("%d\n", y - s.L);
				if (s.l <= x - 1)
					S.insert(shit(s.l, x - 1, s.L, s.R));
				if (x + 1 <= s.r)
					S.insert(shit(x + 1, s.r, s.L, x));
			} else {
				printf("%d\n", x - s.R);
				if (s.l <= x - 1)
					S.insert(shit(s.l, x - 1, y, s.R));
				if (x + 1 <= s.r)
					S.insert(shit(x + 1, s.r, s.L, s.R));
			}
		} else {
			puts("0");
		}
	}

	return 0;
}