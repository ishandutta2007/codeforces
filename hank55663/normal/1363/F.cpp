#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int dp[2005][2005];
int pres[2005][26];
int pret[2005][26];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char s[2005],t[2005];
        scanf("%s %s",t+1,s+1);

        for(int i = 0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j =0;j<26;j++){
                pres[i][j]=pres[i-1][j];
                pret[i][j]=pret[i-1][j];
            }
            pres[i][s[i]-'a']++;
            pret[i][t[i]-'a']++;
        }
        for(int i = 1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(s[i]==t[j]){
                    int ok=1;
                    for(int k=0;k<26;k++){
                        if(pres[i][k]<pret[j][k])ok=0;
                    }
                    if(ok)
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
            }
        }
        sort(s+1,s+n+1);
        sort(t+1,t+n+1);
        int ok=1;
        for(int i = 1;i<=n;i++)
            if(s[i]!=t[i])ok=0;
        if(ok){
            printf("%d\n",n-dp[n][n]);
        }
        else{
            printf("-1\n");
        }
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/