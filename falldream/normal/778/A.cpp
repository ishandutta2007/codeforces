#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long longh
#define INF 2000000000
#define MAXN 200000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
} 

char s2[MAXN+5];
char s[MAXN+5];
int n,m;
int a[MAXN+5];
int p[MAXN+5];

bool check(int x)
{
	int j=1;
	for(int i=1;i<=n&&j<=m;i++)
		if(p[i]>x&&s[i]==s2[j]) ++j;
	if(j>m) return true;
	return false;
}

int main()
{
	scanf("%s",s+1);
	scanf("%s",s2+1);
	n=strlen(s+1);m=strlen(s2+1);
	for(int i=1;i<=n;i++)
	{
	    a[i]=read();
		p[a[i]]=i;
	}
	int l=0,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;	
	}
	cout<<ans;
	return 0;
}