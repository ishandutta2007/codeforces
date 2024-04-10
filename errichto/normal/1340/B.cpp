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

string code[10];
const int nax = 2005;
vector<pair<int,int>> possible[nax];
bool can[2*nax][2*nax];

int diff(string a, string b) {
	int cnt = 0;
	for(int i = 0; i < (int) a.length(); ++i) {
		if(a[i] == '1' && b[i] == '0') {
			return -1;
		}
		if(a[i] != b[i]) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	code[0] = "1110111";
	code[1] = "0010010";
	code[2] = "1011101";
	code[3] = "1011011";
	code[4] = "0111010";
	code[5] = "1101011";
	code[6] = "1101111";
	code[7] = "1010010";
	code[8] = "1111111";
	code[9] = "1111011";
	int n, k;
	cin >> n >> k;
	vector<string> in(n);
	for(string& s : in) {
		cin >> s;
	}
	for(int i = 0; i < n; ++i) {
		string me = in[i];
		for(int maybe = 9; maybe >= 0; --maybe) { //; maybe < 10; ++maybe) {
			int d = diff(me, code[maybe]);
			if(d != -1) {
				possible[i].emplace_back(maybe, d);
				debug() << imie(i) imie(maybe) imie(d);
			}
		}
	}
	can[n][0] = true;
	for(int i = n - 1; i >= 0; --i) {
		for(int prv = 0; prv <= k; ++prv) {
			if(can[i+1][prv]) {
				for(pair<int,int> p : possible[i]) {
					can[i][prv+p.second] = true;
				}
			}
		}
	}
	if(!can[0][k]) {
		cout << -1 << endl;
	}
	else {
		for(int i = 0; i < n; ++i) {
			for(pair<int,int> p : possible[i]) {
				if(k >= p.second && can[i+1][k-p.second]) {
					k -= p.second;
					cout << p.first;
					break;
				}
			}
		}
		cout << endl;
	}
}