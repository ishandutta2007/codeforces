#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 65536
LL dp[10005][2005];
int d[10005];
int inq[10005][2005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++)
    scanf("%d",&d[i]);
    sort(d,d+m);
    for(int i = 0;i<m;i++){
        for(int j=0;j<2005;j++)
            dp[i][j]=2e18;
    }
    dp[0][0]=0;
    int g,r;
    scanf("%d %d",&g,&r);
    queue<pii> q;
    q.push(mp(0,0));
    while(!q.empty()){
        pii p=q.front();
        q.pop();
        inq[p.x][p.y]=0;
        if(p.x==m-1)continue;
        if(p.y==g){
            if(dp[p.x][0]>dp[p.x][p.y]+r){
                dp[p.x][0]=dp[p.x][p.y]+r;
                if(!inq[p.x][0]){
                    q.push(mp(p.x,0));
                    inq[p.x][0]=1;
                }
            }
            continue;
        }
        int x=p.x+1;
        int y=p.y+d[x]-d[x-1];
        if(y<=g){
            if(dp[x][y]>dp[p.x][p.y]+d[x]-d[x-1]){
                dp[x][y]=dp[p.x][p.y]+d[x]-d[x-1];
                if(!inq[x][y]){
                    q.push(mp(x,y));
                    inq[x][y]=0;
                }
            }
        }
        if(p.x!=0){
            int x=p.x-1,y=p.y+d[p.x]-d[p.x-1];
            if(y<=g){
                if(dp[x][y]>dp[p.x][p.y]+d[p.x]-d[p.x-1]){
                    dp[x][y]=dp[p.x][p.y]+d[p.x]-d[p.x-1];
                    if(!inq[x][y]){
                        q.push(mp(x,y));
                        inq[x][y]=0;
                    }
                }
            }
        }
    }
    LL ans=2e18;
    for(int i = 0;i<=g;i++)ans=min(ans,dp[m-1][i]);
    if(ans>1e18){
        printf("-1\n");
    }
    else{
        printf("%lld\n",ans);
    }

}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/