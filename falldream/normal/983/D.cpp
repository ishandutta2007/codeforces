#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define MN 100000
#define G() st[x].lower_bound((Li){L,0,0})
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Rec{int x1,y1,x2,y2;}s[MN+5];
int n,Lx[MN*2+5],Ly[MN*2+5],numx,numy,ans,vis[MN+5],B,C,cnt,rt[55];
struct Li{int l,r,v;}a[MN+5],b[MN+5],c[MN+5];
struct Tree{int l,r,mx,x;short d;}T[4000005];
struct cmp{bool operator()(const Li&a,const Li&b){return a.l==b.l?(a.r==b.r?a.v<b.v:a.r<b.r):a.l<b.l;}};
set<Li,cmp> st[524295];set<Li,cmp>::iterator it;
void Ins(int x,int lt,int rt,int l,int r,int L,int R,int now)
{
    if(l==lt&&r==rt)
    {
        it=G();
        if(it!=st[x].begin())
        {
            --it;Li y=*it;
            if(it->r>R)
            {
                st[x].erase(it);
                st[x].insert((Li){y.l,L-1,y.v});
                st[x].insert((Li){R+1,y.r,y.v});
            }
            else if(it->r>=L)
            {
                st[x].erase(it);
                st[x].insert((Li){y.l,L-1,y.v});
            }
        }
        for(it=G();it->l<=R;it=G())
        {
            Li y=*it;st[x].erase(it);
            if(y.r>R) st[x].insert((Li){R+1,y.r,y.v});
        }
        st[x].insert((Li){L,R,now});
        return;
    }
    int mid=lt+rt>>1;
    if(r<=mid) Ins(x<<1,lt,mid,l,r,L,R,now);
    else if(l>mid) Ins(x<<1|1,mid+1,rt,l,r,L,R,now);
    else Ins(x<<1,lt,mid,l,mid,L,R,now),Ins(x<<1|1,mid+1,rt,mid+1,r,L,R,now);
}
void Build(int x,int l,int r)
{
    if(st[x].insert((Li){1,numy,0}),l==r) return;
    int mid=l+r>>1;
    Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);
}
int now_dep;
inline int newnode(int x){return T[x].d==now_dep?x:(T[++cnt]=T[x],T[cnt].d=now_dep,cnt);}
inline void update(int x){T[x].mx=max(T[x].x,min(T[T[x].l].mx,T[T[x].r].mx));}
void Modify(int x,int lt,int rt,int l,int r,int v)
{
    if(lt==l&&rt==r){T[x].x=max(T[x].x,v);T[x].mx=max(T[x].mx,v);return;}
    int mid=lt+rt>>1;
    if(r<=mid) Modify(T[x].l=newnode(T[x].l),lt,mid,l,r,v);
    else if(l>mid) Modify(T[x].r=newnode(T[x].r),mid+1,rt,l,r,v);
    else Modify(T[x].l=newnode(T[x].l),lt,mid,l,mid,v),
         Modify(T[x].r=newnode(T[x].r),mid+1,rt,mid+1,r,v);
    update(x);
}
int Query(int x,int lt,int rt,int l,int r)
{
    if(!x) return 0;
    if(lt==l&&rt==r) return T[x].mx;
    int mid=lt+rt>>1;
    if(r<=mid) return max(Query(T[x].l,lt,mid,l,r),T[x].x);
    else if(l>mid) return max(Query(T[x].r,mid+1,rt,l,r),T[x].x);
    else return max(T[x].x,min(Query(T[x].l,lt,mid,l,mid),Query(T[x].r,mid+1,rt,mid+1,r)));
}
void Solve(int x,int l,int r,int dep)
{
    if(l==r)
    {
        for(it=st[x].begin();it!=st[x].end();++it)
            if(Query(rt[dep-1],1,numy,it->l,it->r)<=it->v)
                if(!vis[it->v]) vis[it->v]=1,++ans;
        return;
    }
    now_dep=dep;
    int mid=l+r>>1,A=0,L=x<<1,R=L|1,precnt=cnt;
    rt[dep]=newnode(rt[dep-1]);
    for(it=st[x].begin();it!=st[x].end();++it) Modify(rt[dep],1,numy,it->l,it->r,it->v);
    Solve(L,l,mid,dep+1);Solve(R,mid+1,r,dep+1);B=C=0;
    for(it=st[x].begin();it!=st[x].end();++it) a[++A]=*it;
    st[x].clear();
    for(it=st[L].begin();it!=st[L].end();++it) b[++B]=*it;st[L].clear();
    for(it=st[R].begin();it!=st[R].end();++it) c[++C]=*it;st[R].clear();
    for(int i=1,j=1,k=1;i<=A;++i)
    {
        int ok=0;
        while(j<=B&&b[j].r<a[i].l) ++j;
        while(k<=C&&c[k].r<a[i].l) ++k;
        while(j>1&&b[j-1].r>=a[i].l) --j;
        while(k>1&&c[k-1].r>=a[i].l) --k;
        for(int last=a[i].l-1;!ok&&last<a[i].r;)
        {
        	int v=min(b[j].v,c[k].v),rr=min(b[j].r,c[k].r);
			if(v<=a[i].v&&Query(rt[dep],1,numy,last+1,min(rr,a[i].r))<=a[i].v) ok=1;
			last=rr;
			if(b[j].r==rr) ++j;
			if(c[k].r==rr) ++k;
        }
        if(ok&&!vis[a[i].v]) vis[a[i].v]=1,++ans;
    }
    if(x==1) return;
    for(int i=1,j=1,k=1,last=0;i<=A;)
    {
    //    cout<<i<<" "<<j<<" "<<k<<endl;
        int v=max(a[i].v,min(b[j].v,c[k].v)),rr=min(a[i].r,min(b[j].r,c[k].r));
        st[x].insert((Li){last+1,rr,v});last=rr;
        if(a[i].r==rr) ++i;
        if(b[j].r==rr) ++j;
        if(c[k].r==rr) ++k;
    }
   /* cout<<x<<" "<<l<<" "<<r<<" "<<dep<<" : \n";
    cout<<"A:\n";
    for(int i=1;i<=A;++i) printf("%d %d %d\n",a[i].l,a[i].r,a[i].v);
    cout<<"B:\n";
    for(int i=1;i<=B;++i) printf("%d %d %d\n",b[i].l,b[i].r,b[i].v);
    cout<<"C:\n";
    for(int i=1;i<=C;++i) printf("%d %d %d\n",c[i].l,c[i].r,c[i].v);
    cout<<"D:\n";
    for(it=st[x].begin();it!=st[x].end();++it)
        printf("%d %d %d\n",it->l,it->r,it->v);*/
    //cout<<endl;
    cnt=precnt;
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        s[i].x1=read();s[i].y1=read();
        s[i].x2=read();s[i].y2=read();
        Lx[++numx]=s[i].x1;Lx[++numx]=s[i].x2;
        Ly[++numy]=s[i].y1;Ly[++numy]=s[i].y2;
    }
    sort(Lx+1,Lx+numx+1);numx=unique(Lx+1,Lx+numx+1)-Lx-1;
    sort(Ly+1,Ly+numy+1);numy=unique(Ly+1,Ly+numy+1)-Ly-1;
    Build(1,1,numx);
    for(int i=1;i<=n;++i)
    {
        s[i].x1=lower_bound(Lx+1,Lx+numx+1,s[i].x1)-Lx;
        s[i].x2=lower_bound(Lx+1,Lx+numx+1,s[i].x2)-Lx-1;
        s[i].y1=lower_bound(Ly+1,Ly+numy+1,s[i].y1)-Ly;
        s[i].y2=lower_bound(Ly+1,Ly+numy+1,s[i].y2)-Ly-1;
        Ins(1,1,numx,s[i].x1,s[i].x2,s[i].y1,s[i].y2,i);
    }
    Solve(1,1,numx,1);
    printf("%d\n",ans);
    return 0;
}