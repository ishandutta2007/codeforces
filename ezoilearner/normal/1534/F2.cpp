#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

int n,m;
#define Maxn 400010
char ch[Maxn];
int a[Maxn],b[Maxn],c[Maxn];
int id(int i,int j){return (i-1)*m+j;}
int nx[4]={-1,1,0,0},ny[4]={0,0,-1,1};

int L[Maxn],R[Maxn];
int head[Maxn],v[Maxn*7],nxt[Maxn*7],tot=0;
inline void add_edge(int s,int e){tot++;v[tot]=e;nxt[tot]=head[s];head[s]=tot;}
void dfs(int u,int *vis,int t){
    if(vis[u])return;
    vis[u]=t;
    for(int i=head[u];i;i=nxt[i])dfs(v[i],vis,t);
}

pii seq[Maxn];int cnt=0;
pii hh[Maxn];int len=0;

int main(){
    rd(n);rd(m);
    int tmp=0;
    rep(i,1,n){
        tmp++;scanf("%s",ch+tmp);
        tmp+=m-1;
    }
    rep(i,1,m)rd(a[i]);
    rep(x,1,n)rep(y,1,m)
    if(ch[id(x,y)]=='#'){
    rep(t,0,3)
        if(x+nx[t]>=1&&x+nx[t]<=n&&y+ny[t]>=1&&y+ny[t]<=m&&ch[id(x+nx[t],y+ny[t])]=='#')
            add_edge(id(x,y),id(x+nx[t],y+ny[t]));
    }
    rep(j,1,m){
        int lst=-1;
        b[j]=-1;int z=0,cur=0;c[j]=-1;
        rep(i,1,n)
            if(ch[id(i,j)]=='#')cur++;
        a[j]=cur+1-a[j];
        rep(i,1,n+1)
            if(i==n+1||ch[id(i,j)]=='#'){
                if(lst!=-1){
                    if(i<=n)add_edge(id(lst,j),id(i,j));
                    rep(k,lst+1,i-1)
                        if(j>1&&ch[id(k,j-1)]=='#')add_edge(id(lst,j),id(k,j-1));
                    rep(k,lst+1,i-1)
                        if(j<m&&ch[id(k,j+1)]=='#')add_edge(id(lst,j),id(k,j+1));
                }
                if(i==n+1)break;
                lst=i;
                z++;
                if(z==a[j])b[j]=id(i,j);
                if(z==1)c[j]=id(i,j);
            }
    }
    rep(j,1,m)
        if(c[j]!=-1)dfs(c[j],L,j);
    per(j,m,1)
        if(c[j]!=-1)dfs(c[j],R,j);
    rep(j,1,m)
        if(b[j]!=-1)seq[++cnt]=pii(L[b[j]],R[b[j]]);
    sort(seq+1,seq+cnt+1);
    int zz=m+1;
    per(i,cnt,1)
        if(seq[i].SE<zz){
            hh[++len]=seq[i];zz=seq[i].SE;
        }
    int ans=0;
    reverse(hh+1,hh+len+1);
    for(int i=1,j;i<=len;i=j+1){
        j=i;
        while(j+1&&hh[j+1].FR<=hh[i].SE)j++;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}