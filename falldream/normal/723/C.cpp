#include<iostream>
#include<cstdio>
#define INF 2000000000
#define ll long long
#define MAXN 2000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,s[MAXN+5];
int num[MAXN+5];
bool b[MAXN+5];
int ans=0;
int main()
{
	n=read();m=read();
    for(int i=1;i<=n;i++)
    {
    	s[i]=read();
    }
    int x=n/m;
    cout<<x<<" ";
    for(int i=1;i<=n;i++)
    {
    	if(s[i]>m)
    	{
    		b[i]=1;
    	}
    	else
    	if(num[s[i]]<x)
    	{
    		num[s[i]]++;
    	}
    	else
    	    b[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
    	if(b[i])
    	{
    		for(int j=1;j<=m;j++)
    		   if(num[j]<x)
    		      {
    		      	  num[j]++;
    		      	  s[i]=j;
				  	  ans++;
				  	  break;
    		      }
    	    //if(yes==false)
    	      //if(s[i]>m)
    	       //  s[i]=1,ans++;
    	}
    }
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	   cout<<s[i]<<" ";
	return 0;
}