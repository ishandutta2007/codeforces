#include <stdio.h>
#include <cmath>
#define MOD 1000000007

using namespace std;

int n;
char field[3][100005];
char fieldSaved[3][100005];
int dp[10005][8];

long long solve(){
    for(int i=0; i <= n; ++i)
        for(int j=0; j < 8; ++j)
            dp[i][j]=0;
    dp[0][0]=1;
    for(int i=0; i < n; ++i)
        for(int j=0; j < 8; ++j){
            int e[2][3];
            for(int k=0; k < 2; ++k)
                for(int m=0; m < 3; ++m){
                    if(i == n-1 && k == 1)
                        e[k][m]=0;
                    else
                        e[k][m]=field[m][i+k]=='.'?1:0;
                }
            if(j&1)
                e[0][0]=0;
            if(j&2)
                e[0][1]=0;
            if(j&4)
                e[0][2]=0;
            if(e[0][0] && e[0][1])
                dp[i][j+3]=(dp[i][j+3]+dp[i][j])%MOD;
            if(e[0][2] && e[0][1])
                dp[i][j+6]=(dp[i][j+6]+dp[i][j])%MOD;
            if(e[0][0] && !e[1][0])
                continue;
            if(e[0][1] && !e[1][1])
                continue;
            if(e[0][2] && !e[1][2])
                continue;
            int k=e[0][0]+e[0][1]*2+e[0][2]*4;
            dp[i+1][k]=(dp[i+1][k]+dp[i][j])%MOD;
        }
    int k=0;
    if(field[0][n-1] == '.')
        k += 1;
    if(field[1][n-1] == '.')
        k += 2;
    if(field[2][n-1] == '.')
        k += 4;
    return dp[n-1][k];
}

bool testInside(int x, int y){
    if(x < 0 || y < 0 || x >= 3 || y >= n)
        return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i < 3; ++i)
        scanf("%s", field[i]);
    int oPos[2];
    for(int i=0; i < 3; ++i)
        for(int j=0; j < n; ++j){
            fieldSaved[i][j]=field[i][j];
            if(field[i][j] == 'O'){
                oPos[0]=i;
                oPos[1]=j;
            }
        }
    int test[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    long long ans=0;
    for(int i=1; i < 16; ++i){
        int popcount=0;
        bool possible=1;
        for(int j=0; j < 4; ++j){
            if(!(i&(1<<j)))
                continue;
            ++popcount;
            if(!testInside(oPos[0]+2*test[j][0], oPos[1]+2*test[j][1])){
                possible=0;
                continue;
            }
            if(field[oPos[0]+2*test[j][0]][oPos[1]+2*test[j][1]] != '.' || field[oPos[0]+test[j][0]][oPos[1]+test[j][1]] != '.'){
                possible=0;
                continue;
            }
            field[oPos[0]+2*test[j][0]][oPos[1]+2*test[j][1]]='X';
            field[oPos[0]+test[j][0]][oPos[1]+test[j][1]]='X';
        }
        if(possible){
            long long res=solve();
            if(popcount%2 == 0)
                ans=(ans+MOD-res)%MOD;
            else
                ans=(ans+res)%MOD;
        }
        for(int j=0; j < 3; ++j)
            for(int k=0; k < n; ++k)
                field[j][k]=fieldSaved[j][k];
    }
    printf("%I64d\n", ans);
    return 0;
}