#include<cstdio>
#include<vector>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 131072
using namespace std;
vector<int>e[mx],qs[mx];
struct pr{int x,y;}po[mx];
struct pp{int x,y,z,id;}qu[mx];
int f[mx],h[mx],fa[mx],sz[mx],d[mx],w[mx],top[mx],ans[mx];
int L[mx*2],R[mx*2],n,q,ts,x,y,z,j;
struct dt{int ls,rs,a,al;
    inline friend dt operator +(const dt a,const dt b){dt p;
        p.a=a.a+b.a;if(!a.al&&!b.al)p.a+=f[a.rs+b.ls];
        if(a.al&&b.al)p.al=a.al+b.al;else p.al=0;
        p.ls=a.ls;if(a.al&&!b.al)p.ls=a.al+b.ls;
        p.rs=b.rs;if(!a.al&&b.al)p.rs=a.rs+b.al;return p;
    }
}a[mx*2];
inline bool pocmp(pr x,pr y){return x.x>y.x;}
inline bool qucmp(pp x,pp y){return x.z>y.z;}
void dfs(int x){
    int siz=e[x].size()-1;sz[x]++;
    rep(i,0,siz)
        if(fa[x]!=e[x][i]){
            int tt=e[x][i];h[tt]=h[x]+1;
            fa[tt]=x;po[tt].y=tt;
            po[tt].x=qs[x][i];
            dfs(tt);sz[x]+=sz[tt];
        }
}
void mrk(int x){
    int siz=e[x].size()-1;d[++ts]=x;w[x]=ts;
    rep(i,0,siz)if(fa[x]!=e[x][i])mrk(e[x][i]);
}
void cg(int x,int s){
    if(L[s]==R[s]){
        a[s].ls=0;a[s].rs=0;a[s].a=0;a[s].al=1;return;
    }
    if(x<=R[s*2])cg(x,s*2);else cg(x,s*2+1);a[s]=a[s*2]+a[s*2+1];
}
dt Q(int l,int r,int x){
    if(L[x]==l&&R[x]==r)return a[x];
    if(r<=R[x*2])return Q(l,r,x*2);
    if(l>=L[x*2+1])return Q(l,r,x*2+1);
    return Q(l,R[x*2],x*2)+Q(L[x*2+1],r,x*2+1);
}
int main(){
    L[1]=1;R[1]=mx;
    rep(i,1,mx-1){
        L[i*2]=L[i];R[i*2]=(L[i]+R[i])/2;
        L[i*2+1]=R[i*2]+1;R[i*2+1]=R[i];
    }
    scanf("%d%d",&n,&q);
    rep(i,1,n-1)scanf("%d",&f[i]);
    rep(i,1,n-1){
        scanf("%d%d%d",&x,&y,&z);
        e[x].push_back(y);qs[x].push_back(z);
        e[y].push_back(x);qs[y].push_back(z);
    }
    dfs(1);mrk(1);sort(po+1,po+n+1,pocmp);top[1]=1;
    rep(i,2,n)if(fa[d[i]]!=d[i-1])top[d[i]]=d[i];else top[d[i]]=top[d[i-1]];
    rep(i,1,q)scanf("%d%d%d",&qu[i].x,&qu[i].y,&qu[i].z),qu[i].id=i;
    sort(qu+1,qu+q+1,qucmp);j=1;
    rep(i,1,q){
        for(;j<=n&&po[j].x>=qu[i].z;j++)cg(w[po[j].y],1);
        x=qu[i].x;y=qu[i].y;dt xx,yy,tt,we;int u1=0,u2=0;
        while(top[x]!=top[y])if(h[top[x]]>h[top[y]]){
            we=Q(w[top[x]],w[x],1);
            int tm=we.ls;we.ls=we.rs;we.rs=tm;
            if(u1)xx=xx+we;else xx=we,u1=1;x=fa[top[x]];
        }else{
            we=Q(w[top[y]],w[y],1);
            if(u2)yy=we+yy;else yy=we,u2=1;y=fa[top[y]];
        }
        if(h[x]>h[y]){
            tt=Q(w[y]+1,w[x],1);
            int tm=tt.ls;tt.ls=tt.rs;tt.rs=tm;
        }
        if(h[y]>h[x])tt=Q(w[x]+1,w[y],1);
        if(h[x]==h[y]){
            if(u1)tt=xx;if(u2)tt=yy;
            if(u1&&u2)tt=xx+yy;
        }else{if(u1)tt=xx+tt;if(u2)tt=tt+yy;}
        if(tt.al)ans[qu[i].id]=f[tt.al];
        else ans[qu[i].id]=tt.a+f[tt.ls]+f[tt.rs];
    }
    rep(i,1,q)printf("%d\n",ans[i]);
}