/**
 *    author:  gary
 *    created: 09.09.2021 14:01:21
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=13;
int n,m,k;
bool e[MAXN][MAXN];
LL comb[MAXN][MAXN];
vector<vector<int> > R;
int p[13];
void dfs(int now,int mx){
    if(now==n/2+1){
        vector<int> z;
        rb(i,1,n/2) z.PB(p[i]-1);
        R.PB(z);
        return ;
    }
    rb(z,1,mx+1){
        p[now]=z;
        dfs(now+1,max(z,mx));
    }
}
vector<vector<mp> > R2;
bool used[MAXN];
void dfs2(int now){
    if(now==n+1){
        vector<mp> tmp;
        rb(i,1,n/2){
            tmp.PB(II(p[i]-1,p[i+n/2]-1));
        }
        R2.PB(tmp);
        return ;
    }
    if(now<=n/2){
        rb(j,p[now-1]+1,n){
            p[now]=j;
            used[j]=1;
            dfs2(now+1);
            used[j]=0;
        }
    }
    else{
        rb(j,p[now-n/2]+1,n){
            if(!used[j]){
                p[now]=j;
                used[j]=1;
                dfs2(now+1);
                used[j]=0;
            }
        }
    }
}
const int MOD=(1<<22)-1;
const unsigned int A=10719;
struct Hashtable{
    vector<vector<int> > tmp;
    vector<int> nex;
    int fir[MOD+1];
    Hashtable(){
        fill(fir,fir+MOD+1,-1);
    }
    unsigned int ky(vector<int>& v){
        unsigned int rest=0;
        unsigned int AA=1;
        for(auto it:v){
            rest+=AA*it;
            rest%=MOD;
            AA*=A;
        }
        return rest;
    }
    void insert(vector<int>& v){
        int _=ky(v);
        for(int now=fir[_];now!=-1;now=nex[now]) if(tmp[now]==v) return ;
        nex.PB(fir[_]);
        fir[_]=tmp.size();
        tmp.PB(v);
    }
}table;
int fa[MAXN],cnt[MAXN];
LL fact[MAXN];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
    u=root(u);
    v=root(v);
    fa[min(u,v)]=max(u,v);
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    fact[0]=1;
    rb(i,1,6) fact[i]=1ll*i*fact[i-1];
    dfs(1,0);
    dfs2(1);
    rb(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        v--;
        e[u][v]=e[v][u]=1;
    }
    rb(i,0,k) comb[i][0]=1;
    rb(i,1,k) rb(j,1,k) comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    bool dp[6][1<<6];
    int pre[6];
    for(auto it:R2){
        memset(dp,0,sizeof(dp));
        // cerr<<it.size()<<"!"<<endl;
        // rep(i,it.size()) cerr<<it[i].FIR<<" "<<it[i].SEC<<endl;
        rep(i,it.size()) if(e[it[i].FIR][it[i].SEC]) dp[i][1<<i]=1;
        rep(mask,1<<it.size()) rep(i,it.size()) if(dp[i][mask]){
            // cout<<i<<' '<<mask<<endl;
            rep(j,it.size()){
                if((mask>>j)&1);
                else{
                    int u1,v1,u2,v2;
                    u1=it[i].FIR,v1=it[i].SEC;
                    u2=it[j].FIR,v2=it[j].SEC;
                    if((e[u1][u2]&&e[v1][v2])||(e[u1][v2]&&e[v1][u2]))
                        dp[j][mask|(1<<j)]=1;
                }
            }
        }
        bool ok=false;
        rep(i,it.size()) if(dp[i][(1<<it.size())-1]) ok=1;
        if(ok){        
            for(auto it2:R){
                fill(pre,pre+6,-1);
                rep(i,n) fa[i]=i;
                for(auto it3:it) merge(it3.FIR,it3.SEC);
                rep(i,it2.size()){
                    if(pre[it2[i]]==-1){
                        pre[it2[i]]=i;
                        continue;
                    }
                    // cerr<<i<<"_"<<pre[it2[i]]<<" "<<it2.size()<<endl;
                    merge(it[pre[it2[i]]].FIR,it[i].FIR);
                }
                vector<int> Tmp;
                rep(i,n) Tmp.PB(root(i));
                table.insert(Tmp);
            }
        }
    }
    vector<vector<int> > H=table.tmp;
    LL answer=0;
    for(auto ve:H){
        memset(cnt,0,sizeof(cnt));
        int nonz=0;
        for(auto it:ve){
            nonz+=!cnt[it];
            cnt[it]=1;
        }
        answer+=fact[nonz]*comb[k][nonz];
        // cerr<<nonz<<" "<<k<<" "<<fact[nonz]<<" "<<comb[k][nonz]<<endl;
    }
    cout<<answer<<endl;
    return 0;
}