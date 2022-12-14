#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5];
int n,a[MN+5],b[MN+5],s[MN+5],ne[MN+5];
long long ans=0;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	n=read();ne[n+1]=n+1; 
	for(int i=1;i<=n;++i) a[i]=read(),v[gcd(i,n)].push_back(i);
	for(int i=1;i<n;++i) if(n%i==0)
	{
		memset(s,0,sizeof(s));
		for(int j=0;j<v[i].size();++j) s[v[i][j]]=1;
		for(int j=1;j<=n;++j) s[j]+=s[j-1]; 
		for(int j=1;j<=i;++j) 	
		{
			int mx=0;
			for(int k=j;k<=n;k+=i) mx=max(mx,a[k]);
			for(int k=j;k<=n;k+=i) b[k]=(a[k]==mx);	
		}
		for(int j=n;j;--j) ne[j]=b[j]?ne[j+1]:j;
		for(int j=1;j<=n;++j) 
		{
			int len;
			if(ne[j]>n) len=min(ne[1],j)+n-j;
			else len=ne[j]-j;
			ans+=s[len];
		}
	}
	printf("%lld\n",ans);
	return 0;
}