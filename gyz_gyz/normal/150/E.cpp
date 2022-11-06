//SBAK Team.....pa

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define to ed[p]
#define each(x) for (int p=son[x];p;p=next[p])
#define add(x,y,z) ed[++l]=y,data[l]=z,next[l]=son[x],son[x]=l
#define N 200005
int v[N],son[N],ed[N],data[N],next[N],s[N],f[N],g[N],f0[N],g0[N],q[N];
int n,l,r,mid,x,y,z,V,L,R,S,T,ans;
void cnt(int x,int fa){s[x]=1; each(x) if (to!=fa) cnt(to,x),s[x]+=s[to];}
int find(int x,int fa,int d,int c)
{
    if (c>g[d]) g[d]=c,g0[d]=x;
    each(x) if (fa!=to && s[to]) find(to,x,d+1,c+(data[p]<V?-1:1));
}
int divide(int &x)
{
    int y=0; s[x]=1;
    each(x) {s[x]+=s[to]; if (!y || s[to]>s[y]) y=to;}
    if (s[y]>s[x]/2) s[x]-=s[y],x=y,divide(x);
}
void updata(int &n,int m)
{
    int j=0,h=1,t=0;
    for (int i=m;i && i>=L-n;i--) if (g[i]>-m){
        while (j+i<=R && j<=n){while (h<=t && f[j]>f[q[t]]) t--; q[++t]=j++;}
        while (h<=t && q[h]+i<L) h++;
        if (h<=t && g[i]+f[q[h]]>=0) {ans=1,S=f0[q[h]],T=g0[i]; return;}
        }
    n=max(n,m); for (int i=1;i<=m;i++) if (g[i]>f[i]) f[i]=g[i],f0[i]=g0[i];
}
void work(int x)
{
    if (ans) return; int len=0,lim;
    divide(x),memset(f,200,min(s[x],R)*4+4),f0[f[0]=s[x]=0]=x;
    each(x) if (!ans){lim=min(s[to],R),memset(g,200,lim*4+4);
        if (lim) find(to,x,1,data[p]<V?-1:1),updata(len,lim);}
    each(x) if (s[to]) work(to);
}
int main()
{
    scanf("%d%d%d",&n,&L,&R);
    for (int i=1;i<n;i++) scanf("%d%d%d",&x,&y,&z),v[r++]=z,add(x,y,z),add(y,x,z);
    sort(v,v+r),l=0;
    while (l+1<r) mid=(l+r)/2,V=v[mid],cnt(1,0),ans=0,work(1),ans?l=mid:r=mid;
    V=v[l],cnt(1,0),ans=0,work(1); printf("%d %d\n",S,T); return 0;
}