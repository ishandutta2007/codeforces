#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<pii> v[500005];
int color[500005];
int dis[500005];
void solve(){   
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y,t;
        scanf("%d %d %d",&x,&y,&t);
        v[y].pb(mp(x,t));
    }
    MEMS(color);
    MEMS(dis);
    queue<int> q;
    q.push(n);
    dis[n]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        //printf("%d %d\n",x,dis[x]);
        for(auto it:v[x]){
            if(color[it.x]==-1){
                color[it.x]=it.y^1;
            }
            else{
                if(color[it.x]==it.y){
                    if(dis[it.x]==-1){
                    q.push(it.x);
                    dis[it.x]=dis[x]+1;
                    }
                }
            }
        }
    }
    printf("%d\n",dis[1]);
    for(int i = 1;i<=n;i++){
        printf("%d",max(color[i],0));
    }
    printf("\n");
}
int main(){
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/