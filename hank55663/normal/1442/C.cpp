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
LL dis[200005][60];
pii dis2[200005][2];
int vis[200005][2];
vector<int> v[200005],rv[200005];
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){   
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        //if(i%2==1)x=i+1,y=i+2;
        //else x=i+2,y=i+1;
        v[x].pb(y);
        rv[y].pb(x);
    }
    queue<pii> q1,q2;
    for(int i = 0;i<200005;i++){
        for(int j =0;j<60;j++){
            dis[i][j]=1e18;
        }
    }
    dis[1][0]=0;
    q1.push(mp(1,0));
    int now=0;
    while(!q1.empty()){
        while(!q1.empty()){
            pii p=q1.front();
            q1.pop();

            if(dis[p.x][p.y]!=now)continue;
            for(int i = p.y+1;i<60;i++){
                if(dis[p.x][i]>dis[p.x][p.y]){
                    dis[p.x][i]=dis[p.x][p.y];
                    q1.push(mp(p.x,i));
                }
            }
            if(p.y%2==0){
                for(auto it:v[p.x]){
                    if(dis[it][p.y]>dis[p.x][p.y]+1){
                        dis[it][p.y]=dis[p.x][p.y]+1;
                        q2.push(mp(it,p.y));
                    }
                }
            }
            else{
                for(auto it:rv[p.x]){
                    if(dis[it][p.y]>dis[p.x][p.y]+1){
                        dis[it][p.y]=dis[p.x][p.y]+1;
                        q2.push(mp(it,p.y));
                    }
                }
            }
        }
        now++;
        swap(q1,q2);
    }
    LL ans=1e18;
    for(int i = 0;i<60;i++){
        if(dis[n][i]!=-1){
            ans=min(ans,dis[n][i]+(1ll<<i)-1);
        }
    }
    //int mod=998244353;
    if(ans!=1e18){
        printf("%lld\n",ans%mod);
    }
    else{
        priority_queue<pair<pii,pii>,vector<pair<pii,pii> >,greater<pair<pii,pii> > > pq;
        MEMS(dis2);
        pq.push(mp(mp(0,0),mp(1,0)));
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            if(dis2[p.y.x][p.y.y].x!=-1)continue;
            dis2[p.y.x][p.y.y]=p.x;
            pii pp=p.y;
            if(pp.y==0){
                for(auto it:v[pp.x]){
                    if(dis2[it][pp.y].x==-1){
                        pq.push(mp(mp(p.x.x,p.x.y+1),mp(it,pp.y)));
                    }
                }
            }
            else{
                for(auto it:rv[pp.x]){
                    if(dis2[it][pp.y].x==-1){
                        pq.push(mp(mp(p.x.x,p.x.y+1),mp(it,pp.y)));
                    }
                }
            }
            if(dis2[pp.x][pp.y^1].x==-1){
                pq.push(mp(mp(p.x.x+1,p.x.y),mp(pp.x,pp.y^1)));
            }
        }
      //  printf("%lld %lld %lld %lld\n",dis2[n][0].x,dis2[n][0].y,dis2[n][1].x,dis2[n][1].y);
        if(dis2[n][0].x<dis2[n][1].x)
        printf("%lld\n",((f_pow(2,dis2[n][0].x)-1+dis2[n][0].y)%mod+mod)%mod);
        else
        printf("%lld\n",((f_pow(2,dis2[n][1].x)-1+dis2[n][1].y)%mod+mod)%mod);
        
    }
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*


*/