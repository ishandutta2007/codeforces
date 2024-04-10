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
#define index Index
#define MXN 1000000
vector<int> v[200005];
int dis[200005];
int degree[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[y].pb(x);
        degree[x]++;
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    fill(dis,dis+n+1,-1);
   // dis[n]=0;
    pq.push(mp(0,n));
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        if(dis[p.y]!=-1)continue;
        dis[p.y]=p.x;
        for(auto it:v[p.y]){
         //   printf("%d\n",it);
            if(dis[it]==-1){
                degree[it]--;
                pq.push(mp(dis[p.y]+1+degree[it],it));
            }
        }
    }
    printf("%d\n",dis[1]);
    
}
int main(){
 //   srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);
    //int res=0;
   
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}