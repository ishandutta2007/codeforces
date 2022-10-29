#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 50;
int g[MAXN][MAXN];
int dp[MAXN],best;
int n;
//int pre[MAXN],path[MAXN]; // 

bool dfs(int *id,int top,int cnt){
    if(!top){
        if(best<cnt){
            //copy( pre+1,pre+cnt+1,path ); // 
            best = cnt;
            return true;
        }
        return false;
    }
    int a[MAXN];
    for (int i = 0; i < top; i ++){
        if(cnt+top-i<=best)return false;
        if(cnt+dp[id[i]]<=best)return false;
        //pre[cnt] = id[i]; // 
        int k = 0;
        for(int j=i+1;j<top;j++)
            if(g[id[i]][id[j]])
                a[k++] = id[j];
        if(dfs(a,k,cnt+1))return true;
    }
    return false;
}

inline int solve(int n){
    int id[MAXN];
    best = 0;
    for(int i=n-1;i>=0;i--){
        int top = 0;
        for(int j=i+1;j<n;j++)
            if(g[i][j])
                id[top++] = j;
        dfs(id,top,1);
        dp[i] = best;
    }
    return best;
}
int main() {
    int k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j ++)
            scanf("%d", &g[i][j]);
    int x = solve(n);
    printf("%.10f\n", (double)k * k / x / x * (x * x - x) / 2);
    return 0;
}