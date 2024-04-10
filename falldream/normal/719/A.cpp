#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,s[100];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		s[i]=read();
	}
	if(s[n]==0) cout<<"UP";
	else if(s[n]==15) cout<<"DOWN";
	else if(n==1) cout<<"-1";
	else
	   {
           if(s[n]>s[n-1]) cout<<"UP";
	   	   else if(s[n]<s[n-1]) cout<<"DOWN";
	   }
    return 0;
}