#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
LL dis[200005][2];
vector<pii> v[200005],rv[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(y,w));
        rv[y].pb(mp(x,w));
    }
    MEMS(dis);
    priority_queue<pair<LL,pii>,vector<pair<LL,pii>>,greater<pair<LL,pii>>> pq;
    //dis[0][0]=dis[0][1]=0;
    pq.push(mp(0,mp(1,0)));
    //pq.push(mp(0,mp(0,1)));
    while(!pq.empty()){
        auto p=pq.top();
        pq.pop();
        if(dis[p.y.x][p.y.y]!=-1)continue;
        dis[p.y.x][p.y.y]=p.x;
    //    printf("%d %d\n",p.y.x,p.y.y);
        if(p.y.y==0){
            if(dis[p.y.x][1]==-1)
            pq.push(mp(p.x,mp(p.y.x,1)));
            for(auto it:v[p.y.x]){
                if(dis[it.x][p.y.y]==-1){
                    pq.push(mp(p.x+it.y,mp(it.x,p.y.y)));
                }
            }
        }
        else{
            for(auto it:rv[p.y.x]){
                if(dis[it.x][p.y.y]==-1){
                    pq.push(mp(p.x+it.y,mp(it.x,p.y.y)));
                }
            }
        }
    }
    for(int i = 2;i<=n;i++){
        printf("%lld ",dis[i][1]);
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    for(int T=1;T<=t;T++){
        solve();
    }
   // printf("%d\n",s.size());
}

/*
3 5 7 8
*/