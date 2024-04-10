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

const int MAGIC = 30;

string pref[nax], suf[nax];
set<pair<int,int>> are[nax];

pair<int,int> what(const string & s) {
	int n = s.length();
	int mask = 0;
	for(int i = 0; i < n; ++i)
		if(s[i] == '1')
			mask |= 1 << i;
	return make_pair(n, mask);
}

void solvuj(string x, set<pair<int,int>> & TO) {
	const int n = x.length();
	for(int start = 0; start < n; ++start) {
		string tmp;
		for(int end = start; end < n; ++end) {
			if(end - start >= MAGIC) break;
			tmp += x[end];
			TO.insert(what(tmp));
		}
	}
}

int main() {
	
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string x;
		cin >> x;
		pref[i] = suf[i] = x;
		solvuj(x, are[i]);
		debug() << imie(i) imie(are[i]);
	}
	
	int m;
	cin >> m;
	for(int i = n; i < n + m; ++i) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		are[i] = are[a];
		for(auto x : are[b])
			are[i].insert(x);
		
		pref[i] = pref[a] + pref[b];
		while((int) pref[i].length() > MAGIC)
			pref[i].pop_back();
		
		suf[i] = suf[a] + suf[b];
		reverse(suf[i].begin(), suf[i].end());
		while((int) suf[i].length() > MAGIC)
			suf[i].pop_back();
		reverse(suf[i].begin(), suf[i].end());
		
		solvuj(suf[a] + pref[b], are[i]);
		
		int should = 1, already = 0;
		
		debug() << imie(i) imie(are[i]);
		
		for(pair<int,int> p : are[i]) {
			if(p.first == should) {
				++already;
				if(already == (1 << should)) {
					++should;
					already = 0;
				}
			}
			else break;
		}
		debug() << imie(should) imie(already);
		printf("%d\n", should - 1);
	}
}