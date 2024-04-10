#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 200000
#define N 262144
#define pa pair<int,int>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,len,rk[MN+5],T1[N*2+5],T2[N*2+5];
pa s[MN+5];long long ans=0;
bool cmp(int x,int y){return s[x].second<s[y].second;}
inline void Renew(int*T,int x,int v){for(T[x+=N]=v;x>>=1;)T[x]=max(T[x<<1],T[x<<1|1]);}
inline int Query(int*T,int l,int r)
{
	int res=0;if(l>r) return res;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) res=max(res,T[l+1]);
		if( r&1) res=max(res,T[r-1]);
	}
	return res;
}
int main()
{
	len=read();m=read();n=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read(),rk[i]=i;
	s[n+1].first=len;s[0].first=0;
	sort(s+1,s+n+1);sort(rk+1,rk+n+1,cmp);
	for(int i=0;i<=n;++i) if(s[i+1].first-s[i].first>m) return 0*puts("-1");
	for(int i=1;i<=n;++i)
	{
		int x=rk[i],pre=max(0,max(m,Query(T1,1,x-1))-s[x].first),nx=n+1-Query(T2,x+1,n);
	//	cout<<i<<" "<<x<<" "<<pre<<" "<<nx<<endl;
		if(s[nx].first-s[x].first<=pre) continue;
		int buy=min(m,s[nx].first-s[x].first)-pre;ans+=1LL*s[x].second*buy;
	//	cout<<"buy="<<buy<<endl;
		Renew(T2,x,n+1-x);Renew(T1,x,pre+buy+s[x].first);
	}
	printf("%lld\n",ans);
	return 0;
}