#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
/*
int Max[2][105][105];
char c[105],c2[105];
int main(){
    int k;
    scanf("%d",&k);
    scanf("%s %s",c+1,c2+1);
    
    int n=strlen(c+1),m=strlen(c2+1);
    c[0]=0;
    c[n+1]=1;
    c2[0]=2;
    c2[m+1]=3;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            while(c[i+Max[0][i][j]]==c2[j-Max[0][i][j]]){
                Max[0][i][j]++;
            }
            while(c[i-Max[1][i][j]]==c2[j+Max[1][i][j]]){
                Max[1][i][j]++;
            }
        }
    }
    int dp[105][105];
    MEM(dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j]=1e9;
            for(int a=k;a<=i;a++){
                for(int b=k;b<=j;b++){

                }
            }
            for(int a=k;a<=i;a++){
                dp[i][j]=min(dp[i][j],dp[i-a][j]+a);
            }
            for(int b=k;b<=j;b++){
                dp[i][j]=min(dp[i][j],dp[i][j-b]+b);
            }
        }
    }
}  */
int main(){
    LL n;
    scanf("%lld",&n);
    if(n==1)printf("1\n");
    else{
        set<LL> s;
        for(LL j=2;j*j<=n;j++){
            if(n%j==0){
                s.insert(j);
                while(n%j==0){
                    n/=j;
                }
            }
        }
        if(n!=1)s.insert(n);
        if(s.size()>1)printf("1\n");
        else printf("%lld\n",*s.begin());
    }
}
/*

11111212122112
*/