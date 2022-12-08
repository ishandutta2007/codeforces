#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXN = 2e3 + 100;
const int MAXK = MAXN * MAXN;
const char INF = static_cast<char> (static_cast<int> ('z') + 1);

int N, K;

char grid[MAXN][MAXN];
char ans[MAXN * 2];
int a[MAXN][MAXN];
bool b[MAXN][MAXN];
char c[MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &K);
    
    for(int i = 1;i <= N;i++) scanf(" %s", grid[i] + 1);
    
    for(int i = 0;i <= N;ans[i++] = '\0') for(int j = 0;j <= N;j++) a[i][j] = -1, b[i][j] = false;
    
    a[1][1] = grid[1][1] == 'a';
    
    ans[2] = K ? 'a' : grid[1][1];
    b[1][1] = true;
    
    for(int i = 3;i <= 2*N;i++) {
        char P = INF;
        for(int j = max(1, i - N);j <= N and i - j >= 1;j++) {
            if(!(b[j][i - j] = b[j - 1][i - j] or b[j][i - j - 1])) continue;
            a[j][i - j] = max(a[j - 1][i - j], a[j][i - j - 1]) + (grid[j][i - j] == 'a');
            if(K >= i - 1 - a[j][i - j]) c[j][i - j] = 'a'; else c[j][i - j] = grid[j][i - j];
            if(c[j][i - j] < P) P = c[j][i - j];
        }
        assert(P != INF);
        ans[i] = P;
        for(int j = max(1, i - N);j <= N and i - j >= 1;j++) if(b[j][i - j] and P != c[j][i - j]) b[j][i - j] = false, a[j][i - j] = -1;
    }
    
    printf("%s\n", ans + 2);
    
    return 0;
}