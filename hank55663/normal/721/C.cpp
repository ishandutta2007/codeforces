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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define next Next
#define index Index
vector<pii> v[5005];
int dis[5005][5005];
int from[5005][5005];
int degree[5005];
int main(){
    int n,m,t;
    scanf("%d %d %d",&n,&m,&t);
    queue<int> q;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            dis[i][j]=1e9+1;
        }
    }
    dis[1][1]=0;
    for(int i = 0;i<m;i++){
        int x,y,ti;
        scanf("%d %d %d",&x,&y,&ti);
        v[x].pb(mp(y,ti));
        degree[y]++;
    }
    for(int i = 1;i<=n;i++){
        if(degree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            for(int i=1;i<=5000;i++){
                if(dis[x][i]+it.y<=t&&dis[it.x][i+1]>dis[x][i]+it.y){
                    dis[it.x][i+1]=dis[x][i]+it.y;
                    from[it.x][i+1]=x;
                  //  printf("%d %d %d\n",it.x,i+1,x);
                }
            }
            if(--degree[it.x]==0){
                q.push(it.x);
            }
        }
    }
    for(int i = n;i>=2;i--){
        if(dis[n][i]<=t){
            printf("%d\n",i);
            int now=n;
            vector<int> v;
            v.pb(n);
            for(int j =i;j>1;j--){
               // printf("%d %d %d\n",j,now,from[j][now]);
                now=from[now][j];
                v.pb(now);
            }
            reverse(v.begin(),v.end());
            for(auto it:v)
            printf("%d ",it);
            printf("\n");
            break;
        }
    }
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */