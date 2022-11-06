#include<bits/stdc++.h>
#define ll long long
#define N 400010
#define INF 1e9
using namespace std;
template <typename T> void read(T &x){
	x=0;char c=getchar();int fh=1;
	while (!isdigit(c)){if (c=='-')fh=-1;c=getchar();}
	while (isdigit(c))x=x*10+c-'0',c=getchar();
	x*=fh;
}
struct Info{int nu,ne;}a[N*2],na[N*2];
struct seg{int l,r,mi;}t[N*4];
int num,b[N],m,n,x,y,lo[N],df[N],su,q,nu,nb[N],nst,st[N],va[N],f[N],d[N],si[N],so[N],tp[N],bi[N];
multiset <int> v[N];
void jb(int x,int y){a[++num].nu=y;a[num].ne=b[x];b[x]=num;}
void jnb(int x,int y){na[++nu].nu=y;na[nu].ne=nb[x];nb[x]=nu;}
void tarjan(int x,int fa){
	lo[x]=df[x]=++num;st[++nst]=x;
	for (int y=nb[x];y;y=na[y].ne){
		if (na[y].nu!=fa){
			if (!df[na[y].nu]){
				tarjan(na[y].nu,x);
				lo[x]=min(lo[x],lo[na[y].nu]);
				if (lo[na[y].nu]>=df[x]){
					jb(x,++su);jb(su,x);
					while (st[nst]!=na[y].nu){jb(su,st[nst]);jb(st[nst],su);nst--;}
					jb(su,st[nst]);jb(st[nst],su);nst--;
				}
			}else lo[x]=min(lo[x],df[na[y].nu]);
		}
	}
}
void dfs(int x,int fa,int dep){
	f[x]=fa;d[x]=dep;si[x]=1;
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=fa){
			dfs(a[y].nu,x,dep+1);
			if (x>n){v[x].insert(va[a[y].nu]);}
			si[x]+=si[a[y].nu];
			if (si[a[y].nu]>si[so[x]]) so[x]=a[y].nu;
		}
	}
}
void dfs1(int x){
	bi[x]=++num;
	if (so[x]!=0){tp[so[x]]=tp[x];dfs1(so[x]);}
	for (int y=b[x];y;y=a[y].ne){
		if (a[y].nu!=f[x]&&a[y].nu!=so[x]){
			tp[a[y].nu]=a[y].nu;
			dfs1(a[y].nu);
		}
	}
}
int quem(int nu,int l,int r){
	if (t[nu].l==l&&t[nu].r==r) return t[nu].mi;
	int mid=(t[nu].l+t[nu].r)/2;
	if (l>mid) return quem(nu*2+1,l,r);
	if (r<=mid) return quem(nu*2,l,r);
	return min(quem(nu*2,l,mid),quem(nu*2+1,mid+1,r));
}
int que(int x,int y){
	int no=INF;
	while (tp[x]!=tp[y]){
		if (d[tp[x]]<d[tp[y]])swap(x,y);
		no=min(no,quem(1,bi[tp[x]],bi[x]));
		x=f[tp[x]];
	}
	if (d[x]>d[y]) swap(x,y);
	no=min(no,quem(1,bi[x],bi[y]));
	if (x>n)no=min(no,quem(1,bi[f[x]],bi[f[x]]));
	return no;
}
void build(int nu,int l,int r){
	t[nu].l=l;t[nu].r=r;t[nu].mi=0;
	if (l!=r){build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);t[nu].mi=min(t[nu*2].mi,t[nu*2+1].mi);}
}
int man(int x){multiset<int>::iterator i=v[x].begin();return *i;}
void chan(int nu,int we,int x){
	if (t[nu].l==t[nu].r){t[nu].mi=x;return ;}
	if (we<=(t[nu].l+t[nu].r)/2) chan(nu*2,we,x);else chan(nu*2+1,we,x);
	t[nu].mi=min(t[nu*2].mi,t[nu*2+1].mi);
}
void work(int x,int y,int z){
	multiset<int>::iterator i=v[x].find(y);v[x].erase(i);v[x].insert(z);
	chan(1,bi[x],man(x));
}
int main(){
	read(n);read(m);read(q);su=n;
	for (int i=1;i<=n;i++)read(va[i]);
	for (int i=1;i<=m;i++){read(x);read(y);jnb(x,y);jnb(y,x);}
	for (int i=1;i<=n;i++)if(!df[i])tarjan(i,0);
	dfs(1,0,1);tp[1]=1;num=0;dfs1(1);
	build(1,1,su);
	for (int i=1;i<=su;i++) if (i<=n)chan(1,bi[i],va[i]);else chan(1,bi[i],man(i));
	while (q--){
		char ch=getchar();
		while (ch!='A'&&ch!='C')ch=getchar();
		if (ch=='A'){
			read(x);read(y);
			printf("%d\n",que(x,y));
		}else{
			read(x);read(y);
			chan(1,bi[x],y);
			if (f[x])work(f[x],va[x],y);
			va[x]=y;
		}
	}
	return 0;
}