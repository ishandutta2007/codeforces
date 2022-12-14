#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define pa pair<int,int> 
#define MN 15000
const int p=10000019,q=1000000007;
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
long long ff[25][1005],f[1005],Ans[MN*10+5];
int n,k,bg[MN+5],ed[MN+5],cnt=0,num=0;pa s[MN+5];
struct Tree{int l,r;vector<pa> v;}T[MN*10+5];

void Ins(int x,int l,int r,pa k)
{
//	cout<<"ins"<<l<<" "<<r<<" "<<k.first<<" "<<k.second<<endl;
	if(T[x].l==l&&T[x].r==r) {T[x].v.push_back(k);return;}	
	int mid=T[x].l+T[x].r>>1;
	if(r<=mid) Ins(x<<1,l,r,k);
	else if(l>mid) Ins(x<<1|1,l,r,k);
	else Ins(x<<1,l,mid,k),Ins(x<<1|1,mid+1,r,k);
}

void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r)) return;
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);	
}

void Ins(int w,int v){for(int i=k-w;i>=0;--i)f[i+w]=max(f[i+w],f[i]+v);}
void Dfs(int x,int dp)
{
	memcpy(ff[dp],f,sizeof(f));
	for(int i=0;i<T[x].v.size();++i) Ins(T[x].v[i].first,T[x].v[i].second);
	if(T[x].l==T[x].r) 
	{
	//	cout<<T[x].l<<" OK !!"<<endl;
	//	for(int i=1;i<=k;++i) printf("%lld ",f[i]);cout<<endl;
		int res=0;
		for(int i=1,j=1;i<=k;++i,j=1LL*j*p%q) res=(res+1LL*j*(f[i]%q))%q;
		Ans[T[x].l]=res;
	}
	else Dfs(x<<1,dp+1),Dfs(x<<1|1,dp+1);
	memcpy(f,ff[dp],sizeof(f));
}

int main()
{
	n=read();k=read();
	for(int i=1;i<=n;++i) s[i].second=read(),s[i].first=read(),bg[i]=1;
	int q=read();
	for(int i=1;i<=q;++i)
	{
		int op=read();	
		if(op==3) ++cnt;
		else if(op==2) {int x=read();ed[x]=cnt==0?-1:cnt;}
		else {++num;bg[n+num]=cnt+1;s[n+num].second=read();s[n+num].first=read();}
	}
	Build(1,1,cnt);
	for(int i=1;i<=n+num;++i)
	{
		if(!ed[i]) ed[i]=cnt;
		if(bg[i]<=ed[i]) Ins(1,bg[i],ed[i],s[i]);	
	}
	Dfs(1,0);
	for(int i=1;i<=cnt;++i) printf("%lld\n",Ans[i]);
	return 0;
}