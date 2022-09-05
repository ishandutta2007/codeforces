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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "


char sl[1005];
string read() {
	string s;
	scanf("%s", sl);
	int n = strlen(sl);
	for(int i = 0; i < n; ++i) s += sl[i];
	//cout << "dupsko " << s << "\n";
	return s;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	set<string> secik;
	for(int i = 0; i < n; ++i)
		secik.insert(read());
	int common = 0;
	for(int i = 0; i < m; ++i)
		if(secik.find(read()) != secik.end())
			++common;
	bool who = false;
	while(true) {
		if(common) {
			--common;
			--n;
			--m;
			who = !who;
		}
		else if(!who) { // poland
			if(n) {
				--n;
				who = !who;
			}
			else {
				puts("NO");
				return 0;
			}
		}
		else { // enemy
			if(m) {
				--m;
				who = !who;
			}
			else {
				puts("YES");
				return 0;
			}
		}
	}
	assert(false);
}