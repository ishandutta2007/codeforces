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

vector<int> foo(string a, string b) {
	int A = a.length();
	int B = b.length();
	int nxt = 0;
	vector<int> where(B);
	for(int i = 0; i < B; ++i) {
		while(nxt < A && a[nxt] != b[i]) {
			++nxt;
		}
		where[i] = nxt;
		++nxt;
	}
	return where;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	vector<int> pref = foo(a, b);
	debug() << imie(pref);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> suf = foo(a, b);
	debug() << imie(suf);
	reverse(suf.begin(), suf.end());
	int A = a.length();
	int B = b.length();
	for(int& i : suf) {
		i = A - 1 - i;
	}
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	suf.push_back(A);
	debug() << imie(suf);
	vector<bool> ok(A, false);
	set<int> s[26];
	for(int i = 0; i < A; ++i) {
		s[a[i]-'a'].insert(i);
	}
	for(int i = 0; i < B; ++i) {
		int one = (i?pref[i-1]:-1), two = suf[i+1];
		set<int>& secik = s[b[i]-'a'];
		while(true) {
			auto it = secik.lower_bound(one + 1);
			if(it != secik.end() && *it < two) {
				secik.erase(it);
			}
			else {
				break;
			}
		}
	}
	for(int i = 0; i < 26; ++i) {
		if(!s[i].empty()) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
}

// 01234567
// --->  <-
   // b  c
   
// abac