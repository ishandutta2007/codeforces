#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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

typedef long long ll;

int my_pow(int a, int b, int m) {
	int r = 1;
	while(b) {
		if(b % 2) {
			r = (ll) r * a % m;
		}
		a = (ll) a * a % m;
		b /= 2;
	}
	return r;
}
int my_inv(int a, int m) {
	return my_pow(a, m - 2, m);
}

const int nax = 3005;
int mod[2];
char a[nax][nax], b[nax][nax];
int len[nax];
int low[nax], high[nax];
int pw[2][nax], inv[2][nax];
int base[2] = {29, 31};

bool is_prime(int x) {
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int get_mod(unsigned long long ple) {
	int p = 900 * 1000 * 1000 + (ple ^ chrono::steady_clock::now().time_since_epoch().count()) % (100 * 1000 * 1000);
	while(!is_prime(p)) {
		++p;
	}
	return p;
}

void NO() {
	cout << "NO" << endl;
	exit(0);
}

void haszuj(string s, vector<pair<int,int>>& vec) {
	int n = s.length();
	vec.resize(n + 1);
	pair<int,int> p{0, 0};
	for(int i = 0; i < n; ++i) {
		p.first = ((ll) p.first * base[0] + s[i] - 'a') % mod[0];
		p.second = ((ll) p.second * base[1] + s[i] - 'a') % mod[1];
		vec[i+1] = p;
	}
}

//~ void refactor(string& 

int main() {
	mod[0] = get_mod(821375120123952ULL);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%s", a[i]);
		len[i] = strlen(a[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%s", b[i]);
		assert(len[i] == (int) strlen(b[i]));
	}
	mod[1] = get_mod(912388510001211ULL);
	
	for(int i = 0; i < 2; ++i) {
		pw[i][0] = 1;
		for(int j = 1; j < nax; ++j) {
			pw[i][j] = (ll) pw[i][j-1] * base[i] % mod[i];
		}
		for(int j = 0; j < nax; ++j) {
			inv[i][j] = my_inv(pw[i][j], mod[i]);
		}
	}
	
	//~ debug() << imie(mod1) imie(mod2);
	vector<int> changed;
	for(int i = 0; i < n; ++i) {
		low[i] = high[i] = -1;
		for(int j = 0; j < len[i]; ++j) {
			if(a[i][j] != b[i][j]) {
				low[i] = j;
				while(j + 1 < len[i] && a[i][j+1] != b[i][j+1]) {
					++j;
				}
				high[i] = j;
				changed.push_back(i);
				break;
			}
		}
	}
	assert(!changed.empty());
	debug() << imie(changed);
	while(true) {
		bool ok = true;
		for(int i : changed) {
			if(low[i] == 0) {
				ok = false;
			}
		}
		if(!ok) {
			break;
		}
		int j = changed[0];
		for(int i : changed) {
			if(a[i][low[i]-1] != a[j][low[j]-1]) {
				ok = false;
				break;
			}
		}
		if(!ok) {
			break;
		}
		for(int i : changed) {
			--low[i];
		}
	}
	while(true) {
		bool ok = true;
		for(int i : changed) {
			if(high[i] == len[i] - 1) {
				ok = false;
			}
		}
		if(!ok) {
			break;
		}
		int j = changed[0];
		for(int i : changed) {
			if(a[i][high[i]+1] != a[j][high[j]+1]) {
				ok = false;
				break;
			}
		}
		if(!ok) {
			break;
		}
		for(int i : changed) {
			++high[i];
		}
	}
	string FROM, TO;
	for(int i : changed) {
		string A, B;
		for(int j = low[i]; j <= high[i]; ++j) {
			A += a[i][j];
			B += b[i][j];
		}
		if(FROM.empty()) {
			FROM = A;
			TO = B;
		}
		else {
			if(FROM != A || TO != B) {
				NO();
			}
		}
	}
	vector<pair<int,int>> wzo;
	haszuj(FROM, wzo);
	vector<pair<int,int>> pre;
	for(int i = 0; i < nax; ++i) {
		int x = (ll) wzo.back().first * pw[0][i] % mod[0];
		int y = (ll) wzo.back().second * pw[1][i] % mod[1];
		pre.push_back({x, y});
	}
	debug() << imie(FROM) imie(TO) imie(wzo);
	for(int i = 0; i < n; ++i) {
		string s = string(a[i]);
		vector<pair<int,int>> here;
		haszuj(s, here);
		debug() << imie(i) imie(here);
		for(int j = 0; j + (int) FROM.length() <= len[i]; ++j) {
			pair<int,int> L = here[j];
			pair<int,int> R = here[j + (int) FROM.length()];
			int x = (R.first - (ll) L.first * pw[0][FROM.length()]) % mod[0];
			if(x < 0) {
				x += mod[0];
			}
			debug() << imie(i) imie(j) imie(x);
			if(x != wzo.back().first) {
				continue;
			}
			int y = (R.second - (ll) L.second * pw[1][FROM.length()]) % mod[1];
			if(y < 0) {
				y += mod[1];
			}
			if(y != wzo.back().second) {
				continue;
			}
			for(int k = 0; k < (int) FROM.length(); ++k) {
				a[i][j+k] = TO[k];
			}
			break;
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < len[i]; ++j) {
			if(a[i][j] != b[i][j]) {
				NO();
			}
		}
	}
	cout << "YES" << endl;
	cout << FROM << endl;
	cout << TO << endl;
}