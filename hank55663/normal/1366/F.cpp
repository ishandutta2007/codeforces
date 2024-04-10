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
//#define N 262144
#define ULL unsigned long long
#define ll long long
LL dis[2005][2005];
LL inq[2005][2005];
LL w[2005];
vector<pll> v[2005];
int mod=1e9+7;
int main(){
    LL n,m,q;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(int i = 0;i<m;i++){
        LL x,y,a;
        scanf("%lld %lld %lld",&x,&y,&a);
        v[x].pb(mp(y,a));
        v[y].pb(mp(x,a));
        w[x]=max(w[x],a);
        w[y]=max(w[y],a);
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=m;j++){
            dis[i][j]=-1e14;
        }
    }
    dis[1][0]=0;
    queue<pii> qq;
    qq.push(mp(1,0));
    while(!qq.empty()){
        pii p=qq.front();
        qq.pop();
        inq[p.x][p.y]=0;
        if(p.y<m)
        for(auto it:v[p.x]){
            if(dis[it.x][p.y+1]<dis[p.x][p.y]+it.y){
                dis[it.x][p.y+1]=dis[p.x][p.y]+it.y;
                if(!inq[it.x][p.y+1]){
                    qq.push(mp(it.x,p.y+1));
                    inq[it.x][p.y+1]=1;
                }
            }
        }
    }
    LL ans=0;
    for(int i = 1;i<=m;i++){
        LL Max=0;
        for(int j = 1;j<=n;j++){
            Max=max(Max,dis[j][i]);
        }
        ans+=Max;
        ans%=mod;
    }
    vector<pll> seg;
    vector<pair<LL,pll> > stk;
    for(int i = 1;i<=n;i++){
        LL c=-1e15-100;
        for(int j = 0;j<=m;j++){
            c=max(c,(LL)dis[i][j]-j*w[i]);
        }
        seg.pb(mp(w[i],c));
    }
    sort(seg.begin(),seg.end());
    for(auto it:seg){
        LL x=-1e18;
        while(true){
            if(stk.empty())break;
            pair<LL,pll> p=stk.back();
            stk.pop_back();
            if(it.x==p.y.x)continue;
            x=(p.y.y-it.y)/(it.x-p.y.x);
            if(x<=p.x){
                continue;
            }
            else{
                stk.pb(p);
                break;
            }
        }
        stk.pb(mp(x,it));
    }
    for(int i = 0;i<stk.size();i++){
        LL r;
        if(i==stk.size()-1)r=q;
        else r=stk[i+1].x;
        r=min(r,q);
        LL l=max(stk[i].x+1,m+1);
        if(r>=l){
            ans+=((stk[i].y.x*(l%mod)%mod+stk[i].y.y)%mod+
                  (stk[i].y.x*(r%mod)%mod+stk[i].y.y))%mod*(r-l+1)%mod*((mod+1)/2)%mod;
            ans%=mod;
            ans=(ans%mod+mod)%mod;
        }
    }
    printf("%lld\n",ans);
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/