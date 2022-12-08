#pragma GCC target("sse,sse2,sse3,sse4.1,sse4.2,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
    
#include<bits/stdc++.h>
using namespace std;
 
void read(int &x) {
    x=0;int f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
    for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';x*=f;
}
 
void print(int x) {
    if(x<0) putchar('-'),x=-x;
    if(!x) return ;print(x/10),putchar(x%10+48);
}
void write(int x) {if(!x) putchar('0');else print(x);putchar('\n');}
 
#define lf double
#define ll long long 
 
#define pii pair<int,int >
#define vec vector<int >
 
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
 
#define data dfsdjkfkl
 
#define FOR(i,l,r) for(int i=l,i##_r=r;i<=i##_r;i++)
 
const int maxn = 4e5+10;
const int maxm = 1e7+10;
const int inf = 1e9;
const lf eps = 1e-8;
const int mod = 1e9+7;
 
int n,head[maxn],tot,a[maxn],c,in[maxn],out[maxn],f[maxn][20],dep[maxn],q;
struct edge{int to,nxt;}e[maxn<<1];
 
struct data {int u,v,w,a;};
 
void ins(int u,int v) {e[++tot]=(edge){v,head[u]},head[u]=tot;}
 
struct fenwick_tree {
    int t[maxn];
    void modify(int x,int v) {for(;x<=c;x+=x&-x) t[x]+=v;}
    int query(int x,int ans=0) {for(;x;x-=x&-x) ans+=t[x];return ans;}
}T;
 
void dfs(int x,int fa) {
    in[x]=++c;f[x][0]=fa;dep[x]=dep[fa]+1;
    for(int i=1;i<20;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(int i=head[x];i;i=e[i].nxt)
        if(e[i].to!=fa) dfs(e[i].to,x);
    out[x]=++c;
}
 
int lca(int x,int y) {
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;~i;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=19;~i;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
 
 
void modify(int x,int v) {;
    T.modify(in[x],v),T.modify(out[x],-v);
}
 
int query(int x,int y,int t) {
    int ans=T.query(in[x])+T.query(in[y])-T.query(in[t]-1)-T.query(in[t]);
    return ans;
}
 
int mn[maxm],pri[maxm],cnt,vis[maxm];
 
void sieve() {
    for(int i=2;i<maxm;i++) {
        if(!vis[i]) mn[i]=i,pri[++cnt]=i;
        for(int j=1;j<=cnt&&i*pri[j]<maxm;j++) {
            vis[i*pri[j]]=1;mn[i*pri[j]]=pri[j];
            if(i%pri[j]==0) break;
        }
    }
}
 
int qpow(int a,int x) {
    int res=1;
    for(;x;x>>=1,a=1ll*a*a%mod) if(x&1) res=1ll*res*a%mod;
    return res;
}
 
int ans[maxn];
vector<vector<int > > w[maxm];
vector<vector<data > > s[maxm];
 
#define print //cerr<<(lf)(clock()-st)/1e3<<endl
 
int main() {
    int st=clock();
    sieve();read(n);print;
    for(int i=1,x,y;i<n;i++) read(x),read(y),ins(x,y),ins(y,x);
    dfs(1,0);
    vector<int > e;e.clear();
    vector<data > ee;ee.clear();print;
    for(int i=1;i<=n;i++) {
        read(a[i]);
        while(a[i]!=1) {
            int x=mn[a[i]],c=0;
            while(a[i]%x==0) a[i]/=x,c++;
            for(int p=w[x].size();p<=c;p++) w[x].pb(e);
            w[x][c].pb(i);// cerr<<x<<' '<<c<<endl;
        }
    }read(q);
    for(int i=1,u,v,t;i<=q;i++) {
        read(u),read(v),read(t),ans[i]=1;
        while(t!=1) {
            int x=mn[t],c=0;
            while(t%x==0) t/=x,c++;
            for(int p=s[x].size();p<=c;p++) s[x].pb(ee);
            s[x][c].pb((data){u,v,i,lca(u,v)});
        }
    }print;
    for(int x=1;x<maxm;x++) {
        if(vis[x]) continue;
        if(!w[x].size()||!s[x].size()) continue;// cerr<<x<<endl;
        if(w[x].size()>s[x].size()) {
            for(int i=s[x].size();i<w[x].size();i++) s[x].pb(ee);
        } else {
            for(int i=w[x].size();i<s[x].size();i++) w[x].pb(e);
        }
        // cerr<<w[x].size()<<' '<<s[x].size()<<endl;
        for(int i=1;i<w[x].size();i++) {
            for(int j=i;j<w[x].size();j++) 
                for(auto p:w[x][j]) modify(p,1);
            for(auto p:s[x][i]) ans[p.w]=1ll*ans[p.w]*qpow(x,query(p.u,p.v,p.a))%mod;
        }
        for(int i=1;i<w[x].size();i++) 
            for(auto p:w[x][i]) modify(p,-i);
    }
    for(int i=1;i<=q;i++) write(ans[i]);
    print;
    return 0;
}