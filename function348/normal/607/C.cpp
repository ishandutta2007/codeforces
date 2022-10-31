#include<cstdio>
#include<iostream>
using namespace std;
const int N=1000010,base=179,p=1000000007;
int n;
char s[N],t[N];
int a[N],b[N],c[N];
int main()
{
	scanf("%d",&n);n--;
	scanf("%s",s+1);
	scanf("%s",t+1);
	for (int i=1;i<=n;i++) 
	{
		if (s[i]=='N') s[i]='S';else
		if (s[i]=='S') s[i]='N';else
		if (s[i]=='E') s[i]='W';else
		if (s[i]=='W') s[i]='E';
	}
	for (int i=1;i*2<=n;i++) swap(s[i],s[n+1-i]);
	
	for (int i=1;i<=n;i++) a[i]=(1LL*a[i-1]*base+s[i])%p;
	for (int i=1;i<=n;i++) b[i]=(1LL*b[i-1]*base+t[i])%p;
	
	c[0]=1;
	for (int i=1;i<=n;i++) c[i]=1LL*c[i-1]*base%p;
	for (int i=1;i<=n;i++)
	{
		int t2=a[i],t1=(b[n]-1LL*b[n-i]*c[i])%p;
		if (t1<0) t1+=p;
		if (t1==t2) { printf("NO\n");return 0;}
	}
	printf("YES\n");
	return 0;
}