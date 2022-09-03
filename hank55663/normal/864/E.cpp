#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    int n;
    scanf("%d",&n);
    pair<pair<int,pii>,int> pp[105];
    for(int i =1;i<=n;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        b--;
        pp[i]=mp(mp(b,mp(a,c)),i);
    }
    sort(pp+1,pp+n+1);
    pair<int,pii> p[105];
    for(int i = 1;i<=n;i++){
        p[i]=pp[i].x;
    }
    int dp[105][2005];
    int from[105][2005];
    MEM(dp);
    for(int i = 1;i<=n;i++){
        for(int j = 2000;j>=0;j--){
            if(j<=p[i].x&&j>=p[i].y.x&&dp[i][j]<dp[i-1][j-p[i].y.x]+p[i].y.y){
                dp[i][j]=dp[i-1][j-p[i].y.x]+p[i].y.y;
                from[i][j]=j-p[i].y.x;
            }
            if(dp[i][j]<=dp[i-1][j]){
                dp[i][j]=dp[i-1][j];
                from[i][j]=j;
            }
        }
    }
    int ans=-1,ansi;
    for(int i = 0;i<=2000;i++){
        if(dp[n][i]>ans){
            ans=dp[n][i];
            ansi=i;
        }
    }
    printf("%d\n",ans);
    vector<int> v;
    for(int i = n;i>0;i--){
        if(from[i][ansi]!=ansi){
            ansi=from[i][ansi];
            v.pb(pp[i].y);
        }
    }
    reverse(v.begin(),v.end());
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/