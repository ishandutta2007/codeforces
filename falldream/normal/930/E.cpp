#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000
#define N 262144
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> a[MN+5],b[MN+5];
int K,n,m,num,L[MN+5],T1[N*2+5],T2[N*2+5],T3[N*2+5],ans;
inline void R(int&x,int y){(x+=y)>=mod?x-=mod:0;}
inline void Renew(int*T,int x,int v){for(R(T[x+=N],v);x>>=1;)T[x]=(T[x<<1]+T[x<<1|1])%mod;}
int Query(int*T,int l,int r)
{
	if(l>r) return 0;int res=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) R(res,T[l+1]);
		if( r&1) R(res,T[r-1]);
	}
	return res;
}
inline int pow(int x,int k)
{
	int sum=1;
	for(;k;k>>=1,x=1LL*x*x%mod) if(k&1) sum=1LL*sum*x%mod;
	return sum;	
}
bool cmp(pair<int,int> a,pair<int,int> b){return a.second==b.second?a.first>b.first:a.second<b.second;}
int main()
{
	K=read();n=read();m=read();L[num=1]=0; 
	for(int i=1;i<=n;++i)
	{
		a[i].first=read(),a[i].second=read();
		L[++num]=a[i].second;	
	}
	for(int i=1;i<=m;++i)
	{
		b[i].first=read(),b[i].second=read();
		L[++num]=b[i].second;	
	}
	sort(L+1,L+num+1);num=unique(L+1,L+num+1)-L-1;
	sort(a+1,a+n+1,cmp);sort(b+1,b+m+1,cmp);
	Renew(T3,1,1);ans=pow(2,K);
	for(int i=1,j=1;i<=n||j<=m;)
		if(i<=n&&(j>m||a[i].second<b[j].second))
		{
			int x=lower_bound(L+1,L+num+1,a[i].second)-L,
				y=lower_bound(L+1,L+num+1,a[i].first)-L-1;
			int f=mod-(Query(T1,y+1,x)+1LL*pow(2,a[i].first-1)*Query(T3,1,y))%mod;
			ans=(ans+1LL*f*pow(2,K-a[i].second))%mod;
			Renew(T3,x,1LL*f*pow(mod+1>>1,a[i].second)%mod);
			Renew(T1,x,f);int t=a[i].first;
			for(++i;i<=n&&a[i].first<=t;++i);
		}
		else
		{
			int x=lower_bound(L+1,L+num+1,b[j].second)-L,
				y=lower_bound(L+1,L+num+1,b[j].first)-L-1;
			int f=mod-(Query(T2,y+1,x)+1LL*pow(2,b[j].first-1)*Query(T3,1,y))%mod;
			ans=(ans+1LL*f*pow(2,K-b[j].second))%mod;
			Renew(T3,x,1LL*f*pow(mod+1>>1,b[j].second)%mod);
			Renew(T2,x,f);int t=b[j].first;
			for(++j;j<=m&&b[j].first<=t;++j);
		}
	cout<<ans;
	return 0;
}