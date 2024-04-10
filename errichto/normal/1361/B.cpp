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

const int mod = 1e9 + 7;

int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) r = (long long) r * a % mod;
		b /= 2;
		a = (long long) a * a % mod;
	}
	return r;
}
int mul(int a, int b) {
	return (long long) a * b % mod;
}
void mul_self(int& a, int b) {
	a = mul(a, b);
}

void test_case() {
	int n, p;
	scanf("%d%d", &n, &p);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a.rbegin(), a.rend());
	a.push_back(-1);
	n++;
	int advantage = 0;
	bool is_inf = false;
	int prv = a[0];
	for(int x : a) {
		if(prv > x && p != 1) {
			int times = prv - max(0, x);
			debug() << imie(advantage) imie(p) imie(times);
			while(times > 0 && !is_inf && advantage != 0) {
				// cerr << imie(times) imie(p) imie(advantage) << endl;
				times--;
				long long maybe = (long long) advantage * p;
				if(maybe >= mod) {
					is_inf = true;
				}
				advantage = maybe % mod;
			}
			if(times > 0 && is_inf) {
				mul_self(advantage, my_pow(p, times));
			}
		}
		if(x == -1) {
			break;
		}
		if(advantage == 0 && !is_inf) {
			advantage = 1;
		}
		else {
			advantage--;
			if(advantage < 0) {
				advantage += mod;
			}
		}
		prv = x;
	}
	printf("%d\n", advantage);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}