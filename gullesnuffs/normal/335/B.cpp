#include <stdio.h>
#define MAXN 100005

using namespace std;

int nex[MAXN]['z'+1], len;
int dp[MAXN][101], dpUse[MAXN][101];
char s[MAXN];

void rec(int i, int j){
    if(j == 0)
        return;
    printf("%c", s[i]);
    if(j == 1)
        return;
    rec(dpUse[i+1][j-2], j-2);
    printf("%c", s[i]);
}

int main()
{
    scanf("%s", s);
    for(len=0; s[len]; ++len);
    for(int i=len; i <= 2*len; ++i){
        for(char c='a'; c <= 'z'; ++c)
            nex[i][c]=-1;
        for(int j=0; j <= 100; ++j)
            dp[i][j]=MAXN;
    }
    for(int i=len-1; i >= 0; --i){
        for(char c='a'; c <= 'z'; ++c)
            nex[i][c]=nex[i+1][c];
        nex[i][s[i]]=i;
    }
    for(int i=0; i <= len; ++i){
        dp[i][0]=i-1;
        dpUse[i][0]=-1;
        dp[i][1]=i;
        dpUse[i][1]=i;
    }
    for(int j=2; j <= 100; ++j)
        for(int i=len-1; i >= 0; --i){
            dp[i][j]=dp[i+1][j];
            dpUse[i][j]=dpUse[i+1][j];
            if(dp[i+1][j-2] == MAXN)
                continue;
            int a=nex[dp[i+1][j-2]+1][s[i]];
            if(a == -1)
                continue;
            if(a < dp[i][j]){
                dp[i][j]=a;
                dpUse[i][j]=i;
            }
        }
    for(int j=100; j >= 1; --j)
        for(int i=0; i < len; ++i){
            if(dp[i][j] >= MAXN)
                continue;
            rec(dpUse[i][j], j);
            return 0;
        }
    return 0;
}