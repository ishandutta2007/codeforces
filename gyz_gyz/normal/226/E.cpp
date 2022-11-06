#include<cstdio>
#define N 100005
#define get(Ix,sx,x) Ix=v[x]<=S,sx=d[x]-query(rt[i],rt[S],1,m,In[x])
int n,m,type,x,y,z,sx,sy,sz,Ix,Iy,Iz,cx,cy,k,tot,Q,A,S,tmp;
int L[N*25],R[N*25],a[N*25],rt[N],son[N],next[N],In[N],Out[N],v[N],d[N],f[N][20];
void dfs(int x){In[x]=m++; for (int y=son[x];y;y=next[y]) if (!d[y]) d[y]=d[x]+1,dfs(y); Out[x]=m++;}
int lca(int x,int y)
{
    if (d[x]<d[y]) {tmp=x;x=y;y=tmp;}
    for (int i=17;i>=0;i--) if (d[f[x][i]]>d[y]) x=f[x][i]; if (d[x]-d[y]) x=*f[x]; if (x==y) return x;
    for (int i=17;i>=0;i--) if (f[x][i]-f[y][i]) x=f[x][i],y=f[y][i]; return *f[x];
}
void build(int &t,int l,int r)
{
    t=++tot; if (l==r) return; int mid=(l+r)/2;
    build(L[t],l,mid),build(R[t],mid+1,r);
}
void add(int t,int &t1,int l,int r,int x)
{
    t1=++tot; if (l==r){a[t1]=a[t]+A; return;} int mid=(l+r)/2;
    if (x<=mid) R[t1]=R[t],add(L[t],L[t1],l,mid,x); else L[t1]=L[t],add(R[t],R[t1],mid+1,r,x);
    a[t1]=a[L[t1]]+a[R[t1]];
}
int query(int t,int t1,int l,int r,int x)
{
    if (r==x) return a[t]-a[t1]; int mid=(l+r)/2;
    if (x<=mid) return query(L[t],L[t1],l,mid,x);
    return a[L[t]]-a[L[t1]]+query(R[t],R[t1],mid+1,r,x);
}
int work(int i,int x,int sx,int k)
{
    int y=x;
    for (int j=17;j>=0;j--) if (z=f[y][j]) get(Iz,sz,z),y=sx-sz<k?z:y;
    return y;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",f[i]),next[i]=son[*f[i]],son[*f[i]]=i;
    for (int j=0;j<17;j++) for (int i=1;i<=n;i++) f[i][j+1]=f[f[i][j]][j];
    dfs(0),m-=2; build(rt[0],1,m); scanf("%d",&Q);
    for (int i=1;i<=Q;i++){
        scanf("%d%d",&type,&x);
        if (type<2) v[x]=i,A=1,add(rt[i-1],tmp,1,m,In[x]),A=-1,add(tmp,rt[i],1,m,Out[x]);
        else scanf("%d%d%d",&y,&k,&S),z=lca(x,y),rt[i]=rt[i-1],
            get(Ix,sx,x),get(Iy,sy,y),get(Iz,sz,z),cx=sx-sz+Iz,cy=sy-sz,k+=Ix,
            printf("%d\n",cx+cy-Iy<k?-1:cx>=k?work(i,x,sx,k):work(i,y,sy,cy+cx-k+1));
        }
    return 0;
}