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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
vector<pii> v[200005];
set<int> vis[200005];
//int dis[10][10];
bool cmp(const pii &p,const pii &q){
    return p.y<q.y;
}
int main() {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
       // dis[x][y]=dis[y][x]=w;
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
    }
    for(int i = 1;i<=n;i++){
        sort(v[i].begin(),v[i].end(),cmp);
        while(v[i].size()>k){
            v[i].pop_back();
        }
    }
    priority_queue<pair<LL,pii>,vector<pair<LL,pii> > ,greater<pair<LL,pii> > > pq;
    for(int i = 1;i<=n;i++){
        vis[i].insert(i);
        for(auto it:v[i]){
            pq.push(mp(it.y,mp(i,it.x)));
        }
    }
    for(int i = 1;i<=k;i++){
        auto p=pq.top();
        pq.pop();
        
        if(vis[p.y.x].find(p.y.y)!=vis[p.y.x].end()){
            i--;
            continue;
        }
       // printf("%d %d %d\n",p.y.x,p.y.y,p.x);
       // assert(dis[p.y.x][p.y.y]==p.x);
        vis[p.y.x].insert(p.y.y);
        vis[p.y.y].insert(p.y.x);
        if(i==k){
            printf("%lld\n",p.x);
            break;
        }
        for(auto it:v[p.y.y]){
            if(vis[p.y.x].find(it.x)==vis[p.y.x].end()){
                pq.push(mp(p.x+it.y,mp(p.y.x,it.x)));
            }
        }
        for(auto it:v[p.y.x]){
            if(vis[p.y.y].find(it.x)==vis[p.y.y].end()){
                pq.push(mp(p.x+it.y,mp(it.x,p.y.y)));
            }
        }
    }
}