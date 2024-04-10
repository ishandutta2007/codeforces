#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define rep(i,y) for(int i=0;i<y;++i)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define SZ(X) ((int)(X).size())
#define LL long long
#define LD long double
using namespace std;
#define N 300005
#define mod 1000000007

int father[20][N],lv[N],n;
LL dis[N];
vector<int>e[N],ev[N];

void init(int x,int lt){
    father[0][x]=lt;
    rep(i,SZ(e[x])){
        int y=e[x][i];
        if(y!=lt){
            dis[y]=dis[x]+ev[x][i];
            lv[y]=lv[x]+1;
            init(y,x);
        }
    }
}

int adv(int x,int v){
    for(int i=0;(1<<i)<=v;i++){
        if((v>>i)&1)x=father[i][x];
    }
    return x;
}

int lca(int x,int y){
    if(lv[x]>lv[y])x=adv(x,lv[x]-lv[y]);
    else y=adv(y,lv[y]-lv[x]);
    if(x==y)return x;
    for(int i=19;i>=0;i--)
        if(father[i][x]!=father[i][y]){x=father[i][x];y=father[i][y];}
    return father[0][x];
}

void build(){
    init(1,1);
    REPP(i,1,20){
        REPP(x,1,n+1)
            father[i][x]=father[i-1][father[i-1][x]];
    }
}

int num[N],sum[N],sum2[N],all_sum[N],all_sum2[N];
void add(int &x,LL v){
    x=(x+v)%mod;
}

void dfs0(int x,int lt){
    num[x]=1;
    rep(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs0(y,x);
        num[x]+=num[y];
        sum[x]=(sum[x]+sum[y]+(LL)num[y]*ev[x][i])%mod;
        sum2[x]=(sum2[x]+sum2[y]+(LL)sum[y]*2*ev[x][i]+(LL)ev[x][i]*ev[x][i]%mod*num[y])%mod;
    }
}

void dfs1(int x,int lt,LL v1,LL v2){
    v1%=mod;
    v2%=mod;
    if(v1<0)v1+=mod;
    if(v2<0)v2+=mod;
    all_sum[x]=sum[x];
    all_sum2[x]=sum2[x];
    add(all_sum[x],v1);
    add(all_sum2[x],v2);
    rep(i,SZ(e[x])){
        int y=e[x][i];
        if(y==lt)continue;
        dfs1(y,x,
                v1+(LL)(n-num[y])*ev[x][i]%mod+sum[x]-sum[y]-(LL)num[y]*ev[x][i]%mod,
                all_sum2[x]-sum2[y]-sum[y]*2LL*ev[x][i]%mod-(LL)ev[x][i]*ev[x][i]%mod*num[y]+(LL)(n-num[y])*ev[x][i]%mod*ev[x][i]%mod+2LL*ev[x][i]*(v1+sum[x]-sum[y]-(LL)num[y]*ev[x][i]%mod)%mod);
    }
}

int main(){
	
	scanf("%d",&n);
    REPP(i,1,n){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
        e[x].push_back(y);
        ev[x].push_back(v);
        e[y].push_back(x);
        ev[y].push_back(v);
    }
    build();
    dfs0(1,1);
    dfs1(1,1,0,0);
    int Q;
    scanf("%d",&Q);
    while(Q--){
		int u,v;
		scanf("%d%d",&u,&v);
        int me=lca(u,v);
        int an=0;
        LL dd=dis[u]+dis[v]-2*dis[me];
        dd%=mod;
        if(me!=v){
            an=-all_sum2[u]%mod;
            add(an,(sum2[v]+dd*dd%mod*num[v]%mod+dd*2LL*sum[v]%mod)*2);
        }
        else{
            an=all_sum2[u];
            add(an,(all_sum2[v]-sum2[v]+dd*dd%mod*(n-num[v])%mod+dd*2LL*(all_sum[v]-sum[v])%mod)*-2);
        }
        if(an<0)an+=mod;
        printf("%d\n",an);
    }
}