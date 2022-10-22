#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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
#define sorv(V) sort(allv(V))
#define univ(V) (V).erase(unique(allv(V)),(V).end())
#define upmin(a,b) (a)=min((a),(b))
#define upmax(a,b) (a)=max((a),(b))
#define INF (1100000099)
#define INFLL (1100000000000000099ll)
#define MAXN (105)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
inline void fuk() { puts("-1"); exit(0); }

int A[MAXN][MAXN], D[MAXN][MAXN];
int B[MAXN], C[MAXN];
int H, W, Ans;

int main() {
    scanf("%d%d", &H, &W);
    for(int i = 1; i <= H; i++) for(int j = 1; j <= W; j++) scanf("%d", &A[i][j]);
    for(int i = 1; i <= H; i++) {
        B[i] = INF; for(int j = 1; j <= W; j++) upmin(B[i], A[i][j]);
    }
    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) D[i][j] = A[i][j] - B[i];
    }
    for(int i = 1; i <= W; i++) {
        C[i] = D[1][i];
        for(int j = 1; j <= H; j++) if(C[i] != D[j][i]) fuk();
    }
    for(int i = 1; i <= H; i++) if(B[i] < 0) fuk();
    for(int i = 1; i <= W; i++) if(C[i] < 0) fuk();
    if(H > W) {
        int shit = INF;
        for(int i = 1; i <= H; i++) upmin(shit, B[i]);
        for(int i = 1; i <= H; i++) B[i] -= shit;
        for(int i = 1; i <= W; i++) C[i] += shit;
    }
    for(int i = 1; i <= H; i++) Ans += B[i];
    for(int i = 1; i <= W; i++) Ans += C[i];
    printf("%d\n", Ans);
    for(int i = 1; i <= H; i++) {
        for(int j = 0; j < B[i]; j++) printf("row %d\n", i);
    }
    for(int i = 1; i <= W; i++) {
        for(int j = 0; j < C[i]; j++) printf("col %d\n", i);
    }
    return 0;
}