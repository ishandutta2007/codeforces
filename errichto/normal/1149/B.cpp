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

using ll = long long;

const int MAX_N = 1e5 + 5;
char sl[MAX_N];
int nxt[MAX_N][26];
const int MAX_K = 255;
int dp[MAX_K][MAX_K][MAX_K];
const int INF = 1e9 + 5;

void min_self(int& a, int b) {
	a = min(a, b);
}

int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	scanf("%s", sl);
	assert(n == (int) strlen(sl));
	for(int i = 0; i < 26; ++i) {
		nxt[n][i] = INF;
	}
	for(int i = n - 1; i >= 0; --i) {
		for(int j = 0; j < 26; ++j) {
			nxt[i][j] = nxt[i+1][j];
		}
		nxt[i][sl[i]-'a'] = i;
	}
	for(int i = 0; i < MAX_K; ++i) {
		for(int j = 0; j < MAX_K; ++j) {
			for(int k = 0; k < MAX_K; ++k) {
				dp[i][j][k] = INF;
			}
		}
	}
	dp[0][0][0] = 0;
	string s[3];
	while(q--) {
		char type;
		int who;
		scanf(" %c %d", &type, &who);
		--who;
		if(type == '-') {
			s[who].pop_back();
			int L[3] = {0, 0, 0};
			int R[3] = {(int) s[0].length(), (int) s[1].length(), (int) s[2].length()};
			L[who] = R[who] = (int) s[who].length() + 1;
			if(who == 2) {
				for(int a = L[0]; a <= R[0]; ++a) {
					for(int b = L[1]; b <= R[1]; ++b) {
						dp[a][b][L[2]] = INF;
					}
				}
			}
			else {
				for(int a = L[0]; a <= R[0]; ++a) {
					for(int b = L[1]; b <= R[1]; ++b) {
						for(int c = L[2]; c <= R[2]; ++c) {
							dp[a][b][c] = INF;
						}
					}
				}
			}
		}
		else {
			char new_c;
			scanf(" %c", &new_c);
			s[who] += new_c;
			
			int L[3] = {0, 0, 0};
			int R[3] = {(int) s[0].length(), (int) s[1].length(), (int) s[2].length()};
			L[who] = R[who]-1;
			for(int a = L[0]; a <= R[0]; ++a) {
				for(int b = L[1]; b <= R[1]; ++b) {
					for(int c = L[2]; c <= R[2]; ++c) {
						int me = dp[a][b][c];
						if(me >= n) {
							continue;
						}
						if(a < R[0]) min_self(dp[a+1][b][c], nxt[me][s[0][a]-'a'] + 1);
						if(b < R[1]) min_self(dp[a][b+1][c], nxt[me][s[1][b]-'a'] + 1);
						if(c < R[2]) min_self(dp[a][b][c+1], nxt[me][s[2][c]-'a'] + 1);
					}
				}
			}
			
			//~ int len = s[who].length();
			//~ if(who == 0) {
				//~ for(int b = 0; b <= (int) s[1].length(); ++b) {
					//~ for(int c = 0; c <= (int) s[2].length(); ++c) {
						//~ int me = dp[len-1][b][c];
						//~ if(me < n) {
							//~ dp[len][b][c] = nxt[me][new_c-'a'];
						//~ }
						//~ else {
							//~ dp[len][b][c] = INF;
						//~ }
					//~ }
				//~ }
			//~ }
		}
		puts(dp[s[0].length()][s[1].length()][s[2].length()] < INF ? "YES" : "NO");
	}
}