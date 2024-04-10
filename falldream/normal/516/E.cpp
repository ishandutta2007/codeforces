#include<algorithm>
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> a[MN+5],b[MN+5];
int n,m,g,num;long long ans=0;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int pow(int x,int k,int mod)
{
	int sum=1%mod;
	for(;k;k>>=1,x=1LL*x*x%mod)
		if(k&1) sum=1LL*sum*x%mod;
	return sum;
}
inline int phi(int x)
{
	int res=x;
	for(int i=2;i<=100000&&x>1;++i)
		if(x%i==0)
		{
			res=res/i*(i-1);
			while(x%i==0) x/=i;
		}
	if(x^1) res=res/x*(x-1);
	return res;
}
pair<int,long long> s[MN+5];map<int,bool>mp;
long long Solve(const vector<int>&a,const vector<int>&b,int n,int m,int inv)
{
	num=0;int X;long long res=0;if(a.size()==n) return -1;mp.clear();
	for(int i=0;i<a.size();++i)	X=1LL*a[i]*inv%n,s[++num]=make_pair(X,a[i]),mp[X]=1;
	for(int i=0;i<b.size();++i) X=1LL*b[i]*inv%n,s[++num]=make_pair(X,b[i]);
	sort(s+1,s+num+1);int top=num;num=1;
	for(int i=2;i<=top;++i) if(s[i].first!=s[i-1].first) s[++num]=s[i];
	if(num==n)
	for(int i=1,t=1;t<num<<1;++t,i=i%num+1)
	{
		int j=i%num+1;
		s[j].second=min(s[j].second,s[i].second+1LL*(s[j].first-s[i].first+n)%n*m);	
	}
	for(int i=1;i<=num;++i)
	{
		int j=i%num+1;	
		if((s[i].first+1)%n==s[j].first&&mp[s[i].first]) continue;
		res=max(res,1LL*(s[j].first-s[i].first+n-1)%n*m+s[i].second);
	}
	return res;
}
int main()
{
	n=read();m=read();g=gcd(n,m);n/=g;m/=g;
	if(g>MN) return 0*puts("-1");
	for(int i=read(),j;i;--i) j=read(),a[j%g].push_back(j/g);
	for(int i=read(),j;i;--i) j=read(),b[j%g].push_back(j/g);
	for(int i=0;i<g;++i) if(!a[i].size()&&!b[i].size()) return 0*puts("-1");
	int invn=pow(m,phi(n)-1,n),invm=pow(n,phi(m)-1,m);
	for(int i=0;i<g;++i) ans=max(ans,max(Solve(a[i],b[i],n,m,invn),Solve(b[i],a[i],m,n,invm))*g+i);
	printf("%lld\n",ans);
	return 0;
}