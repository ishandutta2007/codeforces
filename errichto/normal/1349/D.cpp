
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

const int MOD = 998244353;
int add(int a, int b) {
	return (a + b) % MOD;
}
int sub(int a, int b) {
	return (a + MOD - b) % MOD;
}
int mul(int a, int b) {
	return (long long) a * b % MOD;
}
int my_pow(int a, int b) {
	int r = 1;
	while(b) {
		if(b % 2) {
			r = mul(r, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return r;
}
int my_inv(int a) {
	return my_pow(a, MOD - 2);
}
int my_div(int a, int b) {
	return mul(a, my_inv(b));
}
void add_self(int& a, int b) {
	a = add(a, b);
}

struct L {
	int a, b; // a*x+b
	L operator +(L l) {
		return L{add(a,l.a), add(b,l.b)};
	}
	L operator -(L l) {
		return L{sub(a,l.a), sub(b,l.b)};
	}
	L operator *(int m) {
		return L{mul(a,m), mul(b,m)};
	}
	void operator +=(L l) {
		*this = *this + l;
	}
	void operator -=(L l) {
		*this = *this - l;
	}
};

vector<int> fac;
int C(int a, int b) {
	return my_div(fac[a], mul(fac[a-b], fac[b]));
}

void solve(vector<int> cnt_cookies) {
	int n = cnt_cookies.size();
	int S = 0;
	for(int a : cnt_cookies) {
		S += a;
	}
	for(int x : cnt_cookies) {
		if(x == S) {
			cout << 0 << endl;
			return;
		}
	}
	fac.resize(S + 1);
	fac[0] = 1;
	for(int i = 1; i <= S; ++i) {
		fac[i] = mul(fac[i-1], i);
	}
	vector<L> ev(S+1, L{0,0});
	ev[1] = L{1, 0}; // 1*x+0
	L ev_pref_sum{0, 0};
	int ratio_pref_sum = 0;
	for(int me = 1; me <= S - 1; ++me) {
		ev_pref_sum += ev[me];
		L &he = ev[me+1];
		he += L{0, n};
		he -= ev[me]*n;
		L A{0, 0};
		A += ev_pref_sum * my_inv(me+1);
		A += ev[1] * my_inv(me+1);
		add_self(ratio_pref_sum, mul(me+1, sub(  my_div(S,me+1), 1)));
		int tmp = my_div(ratio_pref_sum, me + 1);
		A += L{0, tmp};
		he += A * (n - 1);
		he = he * (MOD-1);
	}
	int x = my_div(mul(MOD-1,ev[S].b), ev[S].a);
	vector<int> real_ev(S + 1);
	for(int i = 1; i <= S; ++i) {
		real_ev[i] = add(mul(ev[i].a, x), ev[i].b);
	}
	int answer = 0;
	vector<int> pref_waste(S + 1);
	for(int i = 1; i <= S - 1; ++i) {
		int p_waste = my_div(i, S);
		pref_waste[i] = add(pref_waste[i-1], sub(my_inv(sub(1,p_waste)), 1));// 1 / (1 - p_waste) - 1;
	}
	for(int who = 0; who < n; ++who) {
		int his = cnt_cookies[who];
		for(int remaining = 1; remaining <= his; ++remaining) {
			int p = my_div(my_div(mul(C(his, remaining), C(S-his, 1)), C(S, remaining+1)), (remaining + 1));
			int extra = pref_waste[S-remaining-1];
			add_self(answer, mul(p, add(real_ev[remaining], extra)));
		}
	}
	cout << mul(answer, my_div(n - 1, n)) << endl;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	solve(a);
}