#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
#define MN 100000
#define N 131072
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,a[MN+5],cnt=0,L[MN*2+5],top=0,size,block[MN+5],ti=0,num=0,tot,nn[MN*2+5],R=0,Ans[MN+5],b[MN+5],TT[N*2+5];
struct ques{int t,a,b,id;}q[MN+5];
struct Modi{int a,b,c;}T[MN+5];
bool cmp(const ques&x,const ques&y){return block[x.b]==block[y.b]?x.t<y.t:x.b<y.b;}
void Renew(int x,int v){for(TT[x+=N]+=v;x>>=1;)TT[x]=TT[x<<1]+TT[x<<1|1];}
int Query(int l,int r)
{
	int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res+=TT[l+1];
		if( r&1) res+=TT[r-1];	
	}
	return res;
}

void Add(int x,int ad)
{
	if(nn[x]) Renew(nn[x],-1);
	nn[x]+=ad;
	if(nn[x]) Renew(nn[x], 1);	
}

void Mod(int x,int A,int B)
{
	if(x<=R){Add(A,-1);Add(B, 1);}
	a[x]=B;
}

int main()
{
	tot=n=read();size=sqrt(n);
	for(int i=1;i<=n;++i) block[i]=(i-1)/size+1,L[i]=a[i]=b[i]=read();
	m=read();
	for(int i=1,j,k;i<=m;++i) if(read()==1) k=read(),j=read(),T[++top]=(Modi){j,b[j],k},b[j]=L[++tot]=k;
	else 
	{
		int x=read(),y=read();	
		q[++num]=(ques){top,x==1?1:((x&1)?3:2),y,i};
	}
	sort(L+1,L+tot+1);tot=unique(L+1,L+tot+1)-L-1;
	for(int i=1;i<=n;++i) a[i]=lower_bound(L+1,L+tot+1,a[i])-L;
	sort(q+1,q+num+1,cmp);
	for(int i=1;i<=top;++i) T[i].b=lower_bound(L+1,L+tot+1,T[i].b)-L,
							T[i].c=lower_bound(L+1,L+tot+1,T[i].c)-L;
	for(int i=1;i<=num;++i)
	{
		while(ti<q[i].t) ++ti,Mod(T[ti].a,T[ti].b,T[ti].c);
		while(ti>q[i].t) Mod(T[ti].a,T[ti].c,T[ti].b),--ti;
		while(R<q[i].b) Add(a[++R], 1);
		while(R>q[i].b) Add(a[R--],-1);
		if(q[i].a==1) Ans[q[i].id]=L[a[q[i].b]];
		if(q[i].a==2) Ans[q[i].id]=nn[a[q[i].b]];
		if(q[i].a==3) Ans[q[i].id]=Query(nn[a[q[i].b]],n);
	}
	for(int i=1;i<=m;++i) if(Ans[i]) printf("%d\n",Ans[i]);
	return 0;
}