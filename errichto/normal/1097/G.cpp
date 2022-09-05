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
typedef unsigned long long ull;

const int nax = 1e5 + 5;
const int mod = 1e9 + 7;

const ull MAGIC = 1ULL << 61;

int dp[nax][205];
vector<int> w[nax];
int C[205][205], inv_C[205][205];
int subtree[nax];
ull tmp[205];
int answer[205];

int k;

int root = 1; // TODO: losowac?

void add_self(int& a, int b) {
    a += b;
    if(a >= mod) {
        a -= mod;
    }
}
void sub_self(int& a, int b) {
    a -= b;
    if(a < 0) {
        a += mod;
    }
}

void dfs(int a, int par) {
    //~ debug() << imie(a) imie(par) imie(w[a]);
    dp[a][0] = 2;
    subtree[a] = 1;
    for(int b : w[a]) {
        if(b != par) {
            dfs(b, a);
            for(int i = 0; i <= min(subtree[b], k); ++i) {
                sub_self(answer[i], dp[b][i]);
            }
            for(int i = 0; i < min(subtree[a], k + 1); ++i) {
                for(int j = 0; j <= min(subtree[b], k - i); ++j) {
                    tmp[i+j] += (ull) dp[a][i] * dp[b][j]; // % mod * inv_C[i][i+j]; //C[i+j][i];
                    if(tmp[i+j] >= MAGIC) {
                        tmp[i+j] %= mod;
                    }
                }
                //~ if(i % 8 == 0) {
                    //~ for(int j = 0; j < min(k + 1, subtree[a] + subtree[b]); ++j) {
                        //~ tmp[j] %= mod;
                    //~ }
                //~ }
            }
            subtree[a] += subtree[b];
            for(int i = 0; i < min(k + 1, subtree[a]); ++i) {
                dp[a][i] = tmp[i] % mod;
                tmp[i] = 0;
            }
        }
    }
    for(int i = 0; i < min(k + 1, subtree[a]); ++i) {
        add_self(answer[i], dp[a][i]);
    }
    debug();
    for(int i = 0; i < min(k + 1, subtree[a]); ++i) {
        debug() << imie(a) imie(subtree[a]) imie(i) imie(dp[a][i]);
    }
    if(a != root) {
        for(int i = k; i >= 1; --i) {
            dp[a][i] += dp[a][i-1];
            if(i == 1) {
                --dp[a][i];
                if(dp[a][i] == -1) {
                    dp[a][i] += mod;
                }
            }
            if(dp[a][i] >= mod) {
                dp[a][i] -= mod;
            }
        }
    }
    for(int i = 0; i <= min(k, subtree[a]); ++i) {
        debug() << "X" imie(subtree[a]) imie(i) imie(dp[a][i]);
    }
}

int main() {
    for(int i = 0; i < 205; ++i) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; ++j) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
        }
        for(int j = 0; j <= i; ++j) {
            inv_C[j][i] = C[i][j];
        }
    }
	int n;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        w[a].push_back(b);
        w[b].push_back(a);
    }
    dfs(root, -1);
    debug();
    for(int i = 0; i <= k; ++i) {
        debug() << imie(i) imie(answer[i]);
    }
    
    int total = 0;
    vector<int> ple(k + 1);
    ple[0] = 1;
    for(int rozne = 1; rozne <= k; ++rozne) {
        vector<int> ple2(k + 1);
        for(int already = 0; already <= k; ++already) {
            for(int nowe = 1; nowe + already <= k; ++nowe) {
                ple2[already+nowe] = (ple2[already+nowe] + (ll) ple[already] * C[already+nowe][nowe]) % mod;
            }
        }
        ple = ple2;
        total = (total + (ll) ple[k] * answer[rozne]) % mod;
    }
    printf("%d\n", total);
}