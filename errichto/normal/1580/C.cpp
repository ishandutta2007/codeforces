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

struct Type {
	int cycle, x;
	void read() {
		scanf("%d", &x);
		int y;
		scanf("%d", &y);
		cycle = x + y;
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<Type> types(n);
	for(Type & type : types) {
		type.read();
	}
	vector<int> particular(m + 1);
	int magic = max(1, (int) llround(sqrt(n+m) / 2));
	vector<vector<int>> exact(magic + 1, vector<int>(magic + 1));
	int active = 0;
	vector<int> memo_day(n);
	for(int day = 1; day <= m; ++day) {
		particular[day] += particular[day-1];
		int op, k;
		scanf("%d%d", &op, &k);
		int change = (op == 1 ? +1 : -1);
		k--;
		if(change == +1) {
			memo_day[k] = day;
		}
		active += change;
		Type type = types[k];
		if(type.cycle <= magic) {
			// O(magic)
			for(int i = 0; i < type.x; ++i) {
				exact[type.cycle][(i+memo_day[k])%type.cycle] += change;
			}
		}
		else {
			// O(m/magic)
			for(int start = memo_day[k]; start <= m; start += type.cycle) {
				particular[start] += change;
				if(start + type.x <= m) {
					particular[start+type.x] -= change;
				}
				if(start < day && start+type.x >= day) {
					particular[day] += change;
				}
				// for(int i = 0; i < type.x && start+i <= m; ++i) {
					// particular[start+i] += change;
				// }
			}
		}
		int answer = particular[day];
		// O(magic)
		for(int mod = 1; mod <= magic; ++mod) {
			answer += exact[mod][day % mod];
		}
		debug() << imie(active) imie(answer);
		printf("%d\n", active - answer);
	}
}