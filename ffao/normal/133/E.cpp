#include <string.h>
#include <stdio.h>
#include <algorithm>

using std::max;

char inst[110];
int len, n;

int dp[110][60][2];

int calc(int pos, int tc, int sgn) {  
    if (tc < 0) return -100000;
    
    if (pos == len) {
        if (tc != 0) return -100000;
        else return 0;
    }
    
    if (dp[pos][tc][sgn] == -100000){ 
        int vala = (sgn == 1) ? 1 : -1;
        
        int res = calc(pos,tc-2,sgn);
        if (inst[pos] == 'F') {
            res = max(res, calc(pos+1, tc-1, 1-sgn));
            res = max(res,calc(pos+1, tc, sgn)+vala);
        }
        else {
            res = max(res,calc(pos+1, tc, 1-sgn));
            res = max(res,calc(pos+1, tc-1, sgn)+vala);
        }

        dp[pos][tc][sgn] = res;
    }
    
    return dp[pos][tc][sgn];
    
}

int main () {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= 50; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = -100000;
                }
            }
        }
    
    gets(inst);
    
    len = strlen(inst);
    scanf(" %d", &n);
    int r1 = calc(0, n, 1);
    int r2 = calc(0, n, 0);
    
    /*for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 3; j++) {
            printf("%d ", dp[i][j][0]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j <= 3; j++) {
            printf("%d ", dp[i][j][1]);
        }
        printf("\n");
    }*/
    
    printf("%d\n", max(r1, r2));
}