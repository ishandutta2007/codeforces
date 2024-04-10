#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#define ll long long
#define INF 2000000000
using namespace std;

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int s[5];
int n,ans=0;
int main()
{
	n=read();
	s[1]=s[2]=s[3]=read();
	while(s[1]!=n||s[2]!=n||s[3]!=n)
	{
		for(int i=1;i<=2;i++)
		   for(int j=i+1;j<=3;j++)
		      if(s[i]<s[j])
		      {
		      	  int t=s[i];
		      	  s[i]=s[j];
		      	  s[j]=t;
		      }
		s[3]=min(n,s[1]+s[2]-1);
		ans++;
	}
	cout<<ans;
	return 0;
}