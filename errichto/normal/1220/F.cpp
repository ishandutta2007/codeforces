#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

using ll = long long;

vector<int> g;
const int nax = 5e5 + 5;
int power_two[nax];
int where[nax][21];



int rec(int L, int R) {
	if(L > R) {
		return 0;
	}
	if(L == R) {
		return 1;
	}
	if(L + 1 == R) {
		return 2;
	}
	int two = power_two[R-L+1];
	int i = where[L][two];
	int j = where[R-(1<<two)+1][two];
	debug() << imie(L) imie(R) imie(two) imie(i) imie(j);
	if(g[i] > g[j]) {
		swap(i, j);
	}
	return 1 + max(rec(L, i - 1), rec(i + 1, R));
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	
	
	
	int B = 1;
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		while(B * 2 <= i) {
			B *= 2;
			cnt++;
		}
		power_two[i] = cnt;
	}
	
	
	if(n == 1) {
		puts("1 0");
		return 0;
	}
	vector<int> p(n);
	int one = -1;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		if(p[i] == 1) {
			one = i;
		}
	}
	assert(one != -1);
	vector<int> p2;
	for(int i = 1; i < n; ++i) {
		p2.push_back(p[(one+i)%n] - 2);
	}
	p = p2;
	n = p.size();
	debug() << imie(p);
	g = p;
	int L = 0, R = n - 2;
	
	for(int i = n - 1; i >= 0; --i) {
		where[i][0] = i;
		for(int k = 1; k < 20; ++k) {
			if(i + (1 << k) <= n) {
				int A = where[i][k-1];
				int B = where[i+(1<<(k-1))][k-1];
				if(g[A] > g[B]) {
					swap(A, B);
				}
				where[i][k] = A;
			}
		}
	}
	pair<int,int> answer = {1 + rec(0, n - 1), 0};
		
	
	while(L <= R) {
		int mid = (L + R) / 2;
		int A = rec(0, mid);
		int B = rec(mid + 1, n - 1);
		answer = min(answer, make_pair(1 + max(A, B), mid + 1));
		if(A > B) {
			R = mid - 1;
		}
		else {
			L = mid + 1;
		}
	}
	printf("%d %d\n", answer.first, (answer.second + one + 1) % (n + 1));
	debug() << imie(answer) imie(one);
	// printf("%d\n", answer.first);
}