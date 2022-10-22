#include <stdio.h>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#define MAXN 200000
#define MOD 1000000007

using namespace std;

int n;
int a[2005];
long long dp[2005][2005];
bool used[2005];

int main()
{
    scanf("%d", &n);
    for(int i=0; i < n; ++i){
        scanf("%d", a+i);
        --a[i];
    }
    int bad=0;
    int total=0;
    for(int i=0; i < n; ++i){
        if(a[i] == -2){
            ++total;
            continue;
        }
        used[a[i]]=true;
    }
    for(int i=0; i < n; ++i)
        if(a[i] == -2 && used[i])
            ++bad;
    dp[0][0]=1;
    for(int i=1; i <= n; ++i)
        dp[0][i]=(dp[0][i-1]*i)%MOD;
    for(int i=1; i <= n; ++i)
        for(int j=0; j <= i; ++j){
            if(j)
                dp[j][i]=(dp[j-2][i-1]*(j-1)+dp[j-1][i-1]*(i-j))%MOD;
            else
                dp[j][i]=(dp[j][i-1]*i)%MOD;
        }
    printf("%I64d\n", dp[total-bad][total]);
    return 0;
}