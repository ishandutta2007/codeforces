#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define MAXN 200000
#define INF 2000000000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 
int n,a,b,k;
int cnt=0;
int q[MAXN+5];
int f[MAXN+5];
char s[MAXN+5];
int ss=0;

int main()
{
    n=read();a=read();b=read();k=read();
    scanf("%s",s);  
	for(int i=0;i<n;)
	{
	    while(i<n&&s[i]=='1') i++;
		if(i<n)
		{
		   int nown=0;
		   while(i<n&&s[i]=='0')
		   {
		      nown++;i++;		
		   }
		   if(nown)
		   {
		       q[++cnt]=nown;
		       f[cnt]=i-nown;
			   ss+=nown/b;	
		   } 
		}
	}
	printf("%d\n",ss-a+1);
    for(int i=0;i<n;)
	{
	    while(i<n&&s[i]=='1') i++;
		if(i<n)
		{
		   int nown=0;
		   while(i<n&&s[i]=='0')
		   {
		      nown++;i++;		
		   }
		   if(nown)
		   {
		       while(nown>=b&&ss>=a)
		       {
			       nown-=b;printf("%d ",i-nown);ss--;		
			   }
		   } 
		}
		if(ss<a) break;
	}
   	return 0;
}