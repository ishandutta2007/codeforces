#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <string>
#define pb push_back
#define sz(V) ((int)(V).size())
#define allv(V) ((V).begin()),((V).end())
#define befv(V) ((V)[(sz(V)-2)])
#define upmin(ans,ansx) (ans)=min((ans),(ansx))
#define upmax(ans,ansx) (ans)=max((ans),(ansx))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
#define MOD (1000000007)
#define MAXN (88)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

string cutstr[MAXN][MAXN][MAXN];
int P[MAXN][MAXN][MAXN][3]; // V, K, A
int dp[MAXN][MAXN][MAXN][2];
bool chk[MAXN][MAXN][MAXN][2];
char str[MAXN];
int N, Vn, Kn, An;

int f(const int& V, const int& K, const int& A, const bool ang) {
    if(V+K+A == N) return 0;
    if(chk[V][K][A][ang]) return dp[V][K][A][ang];
    int &ret = dp[V][K][A][ang]; chk[V][K][A][ang] = true;
    ret = INF;
    if(!ang && K != Kn) ret = f(V, K+1, A, false) + P[V][K][A][1];
    if(V != Vn) upmin(ret, f(V+1, K, A, true) + P[V][K][A][0]);
    if(A != An) upmin(ret, f(V, K, A+1, false) + P[V][K][A][2]);
    return ret;
}
int main() {
    scanf("%d %s", &N, str); N = (int)strlen(str);
    for(int i = 0; str[i]; i++) {
        if('V' == str[i]) Vn++;
        else if('K' == str[i]) Kn++;
        else { str[i] = 'A'; An++; }
    }
    for(int v = 0; v <= Vn; v++) for(int k = 0; k <= Kn; k++) for(int a = 0; a <= An; a++) {
        string &S = cutstr[v][k][a];
        for(int i = 0, uv = 0, uk = 0, ua = 0; i < N; i++) {
            if('V' == str[i]) {
                uv++; if(v < uv) S += 'V';
            } else if('K' == str[i]) {
                uk++; if(k < uk) S += 'K';
            } else { ua++; if(a < ua) S += 'A'; }
        }
        fill(P[v][k][a], P[v][k][a]+3, -1);
        for(int i = 0; i < sz(S); i++) {
            if('V' == S[i] && -1 == P[v][k][a][0]) P[v][k][a][0] = i;
            else if('K' == S[i] && -1 == P[v][k][a][1]) P[v][k][a][1] = i;
            else if('A' == S[i] && -1 == P[v][k][a][2]) P[v][k][a][2] = i;
        }
    }
    printf("%d\n", f(0, 0, 0, false));
    return 0;
}