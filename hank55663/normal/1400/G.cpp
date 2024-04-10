#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL fra[300005];
LL inv[300005];
int mod=998244353;
int C(int a,int b){
    if(b>a)return 0;
    return fra[a]*inv[b]%mod*inv[a-b]%mod;
}
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int use[300005];
pii p[300005];
pii edge[300005];
int f[300005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
LL cnt[300005][45];
vector<int> v[300005];
vector<pii> ee[300005];
int used[300005];
int add[300005];
void solve(){
    fra[0]=1;
    for(int i = 1;i<300005;i++)fra[i]=fra[i-1]*i%mod;
    inv[300004]=f_pow(fra[300004],mod-2);
    for(int i = 300003;i>=0;i--)inv[i]=inv[i+1]*(i+1)%mod;
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        edge[i]=mp(x,y);
        use[x]=use[y]=1;
    }
    for(int i = 1;i<=n;i++){
        if(!use[i]){
            add[p[i].x]++;
            add[p[i].y+1]--;
        }
    }
    cnt[0][0]=1;
    for(int i = 1;i<=n;i++){
        int ok=0;
        for(int j  =0;j<m;j++){
            if(p[edge[j].x].x==i||p[edge[j].x].y==i-1||p[edge[j].y].x==i||p[edge[j].y].y==i-1){
                ok=1;
            }
        }
        if(ok){
            for(int j=1;j<=n;j++){
                f[j]=j;
                v[j].clear();
                ee[j].clear();
            }
            for(int j = 0;j<m;j++){
                if(p[edge[j].x].x<=i&&p[edge[j].x].y>=i&&p[edge[j].y].x<=i&&p[edge[j].y].y>=i){
                    int a=Find(edge[j].x);
                    int b=Find(edge[j].y);
                    f[a]=b;
                }
            }
            for(int j = 0;j<m;j++){
                if(p[edge[j].x].x<=i&&p[edge[j].x].y>=i&&p[edge[j].y].x<=i&&p[edge[j].y].y>=i){
                    ee[Find(edge[j].x)].pb(edge[j]);
                }
            }
            for(int j = 1;j<=n;j++){
                if(p[j].x<=i&&p[j].y>=i){
                    v[Find(j)].pb(j);
                }
            }
            LL dp[2][45];
            MEM(dp);
            dp[0][0]=1;
            for(int j = 1;j<=n;j++){
                if(Find(j)==j&&p[j].x<=i&&p[j].y>=i&&use[j]){//v[j].size()>=2){
                    vector<LL> res(v[j].size()+1,0);
                    for(int k=0;k<(1<<(v[j].size()));k++){
                        for(int a=0;a<v[j].size();a++){
                            if(k&(1<<a)){
                                used[v[j][a]]=1;
                            }
                        }
                        int ok=1;
                        for(auto it:ee[j]){
                            if(used[it.x]&&used[it.y])ok=0;
                        }
                        assert(__builtin_popcount(k)<res.size());
                        res[__builtin_popcount(k)]+=ok;
                        for(int a=0;a<v[j].size();a++){
                            if(k&(1<<a)){
                                used[v[j][a]]=0;
                            }
                        }
                    }
                    for(int x=0;x<res.size();x++){
                        for(int y=0;y<45;y++){
                            if(dp[0][y]){
                            dp[1][x+y]+=dp[0][y]*res[x]%mod;
                            dp[1][x+y]%=mod;
                            }
                        }
                    }
                    for(int x=0;x<45;x++){
                        dp[0][x]=dp[1][x];
                        dp[1][x]=0;
                    }
                }
            }
            for(int j = 0;j<45;j++){
                cnt[i][j]=dp[0][j];
              //  printf("%d %d %lld\n",i,j,dp[0][j]);
            }
        }
        else{
            for(int j = 0;j<45;j++){
                cnt[i][j]=cnt[i-1][j];
            }
        }
    }
    int sum=0;
    LL ans=0;
    for(int i = 1;i<=n;i++){
        sum+=add[i];
        for(int j = 0;j<45&&j<=i;j++){
            ans+=C(sum,i-j)*cnt[i][j]%mod;
            ans%=mod;
           // printf("%d %d %d %d\n",i,j,ans,cnt[i][j]);
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/