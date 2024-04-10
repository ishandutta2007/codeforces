#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
int dp[200005];
int d[200005];
vector<int> v[200005];
int DP(int x){
    if(dp[x]!=-1)return dp[x];
    dp[x]=d[x];
    for(auto it:v[x]){
        if(d[it]>d[x])dp[x]=min(dp[x],DP(it));
        else dp[x]=min(dp[x],d[it]);
    }
    return dp[x];
}
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        dp[i]=-1;
        d[i]=-1;
        v[i].clear();
    }
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
    }
    queue<int> q;
    q.push(1);
    d[1]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(d[it]==-1){
                d[it]=d[x]+1;
                q.push(it);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        printf("%d ",DP(i));
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/