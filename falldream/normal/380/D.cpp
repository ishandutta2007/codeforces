#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
#define mod 1000000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pair<int,int> s[MN+5];
int n,num,p[MN+5],inv[MN+5],a[MN+5],ans=0;
inline int C(int n,int m){return m>n?0:1LL*p[n]*inv[m]%mod*inv[n-m]%mod;}
int Solve(int l,int r)
{
//	cout<<"Solve"<<l<<" "<<r<<endl;
	int res=1;
	for(int i=2;i<=num;++i)
	{
		if(s[i].second<l)
		{	
			res=1LL*res*C(s[i].first-s[i-1].first-1,l-s[i].second-1)%mod;
			r+=s[i].first-s[i-1].first-(l-s[i].second);l=s[i].second;
		}
		else if(s[i].second>r) 
		{
			res=1LL*res*C(s[i].first-s[i-1].first-1,s[i].second-r-1)%mod;
			l-=s[i].first-s[i-1].first-(s[i].second-r);r=s[i].second;
		}
	 	else return 0;
//		cout<<"begin"<<i<<" "<<l<<" "<<r<<" res= "<<res<<endl;
	}
	if(l<1||r>n) return 0;
	res=1LL*res*C(n-s[num].first,l-1)%mod;
//	cout<<"res="<<res<<endl;
	return res;
}
int main()
{
	n=read();p[0]=p[1]=inv[0]=inv[1]=1;
	for(int i=2;i<=n;++i) p[i]=1LL*p[i-1]*i%mod,inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;++i) inv[i]=1LL*inv[i-1]*inv[i]%mod;
	for(int i=1;i<=n;++i) if(a[i]=read()) s[++num]=make_pair(a[i],i);
	sort(s+1,s+num+1);
	if(!num)
	{
		for(int i=1;i<=n;++i)
			ans=(ans+C(n-1,i-1))%mod;
		return 0*printf("%d\n",ans);
	}
	int L=0,R=n+1;
	for(int i=1,mn=1e9;i<=s[1].second;++i) 
		if(a[i])
		{
			if(i!=s[1].second) L=i;
			if(a[i]>mn) return 0*puts("0");
			else mn=a[i];
		}
	for(int i=n,mn=1e9;i>=s[1].second;--i)
		if(a[i])
		{
			if(i!=s[1].second) R=i;
			if(a[i]>mn) return 0*puts("0");
			else mn=a[i];	
		}
	int res1=0,res2=0;
	if(s[1].second-(s[1].first-1)>L) res1=Solve(s[1].second-(s[1].first-1),s[1].second);
	if(s[1].second+(s[1].first-1)<R) res2=Solve(s[1].second,s[1].second+(s[1].first-1)); 
	//cout<<"L="<<L<<"R="<<R<<endl;
	for(int i=L+1;i<=s[1].second;++i) 
	{
		if(i==s[1].second&&s[1].first>1) continue;
	//	cout<<i<<" "<<(s[1].second==i?1:C(s[1].first-2,s[1].second-i-1))<<endl;
		ans=(ans+1LL*(s[1].second==i?1:C(s[1].first-2,s[1].second-i-1))*res1)%mod;
	}	
	for(int i=s[1].second+1;i<R;++i) 
		ans=(ans+1LL*C(s[1].first-2,i-s[1].second-1)*res2)%mod;
	printf("%d\n",ans);
	return 0;
}