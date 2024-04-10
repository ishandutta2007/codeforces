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

const int nax = 1e6 + 5;
const int INF = 1e9 + 5;
char str[nax];

struct S {
	int L, R, len;
};

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	vector<S> they;
	for(int i = 0; i < n; ++i) {
		if(str[i] == '1') {
			int j = i;
			while(j + 1 < n && str[j+1] == '1') {
				++j;
			}
			they.push_back(S{i, j, j-i+1});
			debug() << imie(i) imie(j);
			i = j;
		}
	}
	long long answer = 0;
	vector<int> special[2];
	for(int rep = 0; rep < 2; ++rep) {
		vector<S> stack;
		const int FAKE = -2;
		stack.push_back(S{FAKE,FAKE,INF});
		for(S s : they) {
			for(int pref = 1; pref < s.len; ++pref) {
				int fake_pref = pref + (rep == 1);
				int low = 0, high = (int) stack.size() - 1;
				// last >= pref
				int last_greater_eq = -1;
				while(low <= high) {
					int mid = (low + high) / 2;
					if(stack[mid].len >= fake_pref) {
						last_greater_eq = mid;
						low = mid + 1;
					}
					else {
						high = mid - 1;
					}
				}
				assert(last_greater_eq != -1);
				S bad = stack[last_greater_eq];
				int first = (bad.R < 0 ? 0 : bad.R - fake_pref + 2 );
				debug() << imie(rep) imie(s.L) imie(pref) imie(first);
				// if(s.L - first + 1 > 0) {
					// debug() << imie(pref) imie(s.L) imie(first) imie(rep);
				// }
				answer += (long long) pref * (s.L - first + 1);
			}
			while(stack.back().len < s.len) {
				stack.pop_back();
			}
			while(rep == 1 && stack.back().len <= s.len) {
				stack.pop_back();
			}
			// previous >= s.len
			S bad = stack.back();
			int first = (bad.R < 0 ? 0 : bad.R - s.len - (rep == 1) + 2);
			special[rep].push_back(first);
			
			stack.push_back(s);
		}
		
		reverse(they.begin(), they.end());
		for(S& s : they) {
			int new_r = n - 1 - s.L;
			int new_l = n - 1 - s.R;
			s.L = new_l;
			s.R = new_r;
		}
	}
	reverse(special[1].begin(), special[1].end());
	for(int& i : special[1]) {
		i = n - 1 - i;
	}
	debug() << imie(special[0]) imie(special[1]);
	debug() << imie(answer);
	for(int i = 0; i < (int) they.size(); ++i) {
		answer += (long long) they[i].len * (they[i].L - special[0][i] + 1) * (special[1][i] - they[i].R + 1);
	}
	debug() << imie(answer);
	for(S s : they) {
		if(s.len >= 3) {
			for(int len = 1; len <= s.len - 2; ++len) {
				answer += (long long) len * (s.len - 1 - len);
			}
			// long long subs = (long long) s.len * (s.len + 1) / 2;
			// subs -= s.len - 1;
			// subs -= s.len;
			// debug() << imie(s.len) imie(subs);
			// answer += subs;
		}
	}
	printf("%lld\n", answer);
}