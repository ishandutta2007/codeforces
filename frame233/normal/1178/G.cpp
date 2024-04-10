// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
struct edge{
	int v,nxt;
}c[N<<1];
int A[N],B[N];
int front[N],edge_cnt;
Finline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
ll val1[N],val2[N];
int siz[N];
int dfn[N],id,rev[N];
void dfs(int x,int fa,int a,int b)
{
	dfn[x]=++id;
	rev[id]=x;
	a+=A[x],b+=B[x];
	val1[id]=a,val2[id]=abs(b);
	siz[x]=1;
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		if(v!=fa)
		{
			dfs(v,x,a,b);
			siz[x]+=siz[v];
		}
	}
}
const int S=450;
int n,q;
int _q[N],_l,_r;
int t[N],pos;
ll a[N],b[N];
Finline ll X(int x){return -a[x];}
Finline ll Y(int x){return b[x];}
Finline bool check(int a,int b,int c)
{
	if(X(b)==X(c)) return Y(b)<Y(c);
	return (Y(b)-Y(a))*(X(c)-X(b))<=(Y(c)-Y(b))*(X(b)-X(a));
}
Finline bool Check(int a,int b,ll c)
{
	return (Y(b)-Y(a))>=(X(b)-X(a))*c;
}
Finline bool checK(int a,int b,ll c)
{
	return (Y(b)-Y(a))<=(X(b)-X(a))*c;
}
int Q[N][3];
ll ans[N];
int qwq[N];
void solve1(int L,int R)
{
	ll tag=0;
	auto build=[&]()
	{
		_l=1,_r=0;
		pos=0;
		for(int i=L;i<=R;++i) t[++pos]=i;
		std::sort(t+1,t+pos+1,[](int a,int b)->bool{return -val2[a]<-val2[b];});
		for(int i=1;i<=pos;++i)
		{
			a[i]=val2[t[i]];
			b[i]=1ll*val2[t[i]]*val1[t[i]];
			qwq[t[i]]=i;
		}
		for(int i=1;i<=pos;++i)
		{
			while(_l<_r&&check(_q[_r-1],_q[_r],i)) --_r;
			if(_l==_r+1||X(i)!=X(_q[_r])) _q[++_r]=i;
			else if(Y(i)>Y(_q[_r])) _q[_r]=i;
		}
	};
	auto Update=[&](int l,int r,int C)
	{
		if(l==L&&r==R)
		{
			tag+=C;
			return;
		}
		for(int i=1;i<=R-L+1;++i) b[i]+=tag*a[i];
		for(int i=l;i<=r;++i) b[qwq[i]]+=1ll*C*a[qwq[i]];
		tag=0;
		_l=1,_r=0;
		for(int i=1;i<=R-L+1;++i)
		{
			while(_l<_r&&check(_q[_r-1],_q[_r],i)) --_r;
			if(_l==_r+1||X(i)!=X(_q[_r])) _q[++_r]=i;
			else if(Y(i)>Y(_q[_r])) _q[_r]=i;
		}
	};
	auto Query=[&](int l,int r)->ll
	{
		if(l==L&&r==R)
		{
			while(_l<_r&&Check(_q[_l],_q[_l+1],tag)) ++_l;
			return a[_q[_l]]*tag+b[_q[_l]];
		}
		ll ans=0;
		for(int i=l;i<=r;++i)
		{
			chmax(ans,1ll*a[qwq[i]]*tag+b[qwq[i]]);
		}
		return ans;
	};
	build();
	int x,y;
	for(int i=1;i<=q;++i)
	{
		int opt=Q[i][0];
		x=Q[i][1];
		int l=dfn[x],r=dfn[x]+siz[x]-1;
		chmax(l,L);
		chmin(r,R);
		if(l>r) continue;
		if(opt==1)
		{
			y=Q[i][2];
			Update(l,r,y);
		}
		else
		{
			chmax(ans[i],Query(l,r));
		}
	}
}
void solve2(int L,int R)
{
	ll tag=0;
	auto build=[&]()
	{
		_l=1,_r=0;
		pos=0;
		for(int i=L;i<=R;++i) t[++pos]=i;
		std::sort(t+1,t+pos+1,[](int a,int b)->bool{return -val2[a]<-val2[b];});
		for(int i=1;i<=pos;++i)
		{
			a[i]=val2[t[i]];
			b[i]=1ll*val1[t[i]]*val2[t[i]];
			qwq[t[i]]=i;
		}
		for(int i=1;i<=pos;++i)
		{
			while(_l<_r&&check(_q[_r-1],_q[_r],i)) --_r;
			if(_l==_r+1||X(i)!=X(_q[_r])) _q[++_r]=i;
			else if(Y(i)>Y(_q[_r])) _q[_r]=i;
		}
	};
	auto Update=[&](int l,int r,int C)
	{
		if(l==L&&r==R)
		{
			tag+=C;
			return;
		}
		for(int i=1;i<=R-L+1;++i) b[i]+=tag*a[i];
		for(int i=l;i<=r;++i) b[qwq[i]]+=1ll*C*a[qwq[i]];
		tag=0;
		_l=1,_r=0;
		for(int i=1;i<=R-L+1;++i)
		{
			while(_l<_r&&check(_q[_r-1],_q[_r],i)) --_r;
			if(_l==_r+1||X(i)!=X(_q[_r])) _q[++_r]=i;
			else if(Y(i)>Y(_q[_r])) _q[_r]=i;
		}
	};
	auto Query=[&](int l,int r)->ll
	{
		if(l==L&&r==R)
		{
			while(_l<_r&&checK(_q[_r-1],_q[_r],tag)) --_r;
			return a[_q[_r]]*tag+b[_q[_r]];
		}
		ll ans=0;
		for(int i=l;i<=r;++i)
		{
			chmax(ans,1ll*a[qwq[i]]*tag+b[qwq[i]]);
		}
		return ans;
	};
	build();
	int x,y;
	for(int i=1;i<=q;++i)
	{
		int opt=Q[i][0];
		x=Q[i][1];
		int l=dfn[x],r=dfn[x]+siz[x]-1;
		chmax(l,L);
		chmin(r,R);
		if(l>r) continue;
		if(opt==1)
		{
			y=Q[i][2];
			Update(l,r,y);
		}
		else
		{
			chmax(ans[i],Query(l,r));
		}
	}
}
int main()
{
	read(n,q);
	int x;
	for(int i=2;i<=n;++i)
	{
		read(x);
		addedge(x,i);
	}
	for(int i=1;i<=n;++i) read(A[i]);
	for(int i=1;i<=n;++i) read(B[i]);
	dfs(1,0,0,0);
	for(int i=1;i<=q;++i)
	{
		read(Q[i][0],Q[i][1]);
		if(Q[i][0]==1) read(Q[i][2]);
	}
	for(int l=1,r=S;l<=n;l+=S,r+=S)
	{
		chmin(r,n);
		solve2(l,r);
	}
	for(int i=1;i<=n;++i) val1[i]=-val1[i];
	for(int i=1;i<=q;++i) Q[i][2]=-Q[i][2];
	for(int l=1,r=S;l<=n;l+=S,r+=S)
	{
		chmin(r,n);
		solve1(l,r);
	}
	for(int i=1;i<=q;++i)
	{
		if(Q[i][0]==2)
		{
			printf("%lld\n",ans[i]);
		}
	}
	return 0;
}