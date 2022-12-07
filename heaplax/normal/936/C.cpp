#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;
}
using namespace std;
int n,cnt[26],top,st[6333];
char s[2005],t[2005],tmp[2005];
void rev(int x)
{
	reverse(s+x,s+n+1);
	for(int i=1;i<x;++i)tmp[i]=s[i];
	for(int i=x;i<=n;++i)
		s[i-x+1]=s[i];
	for(int i=n-x+2;i<=n;++i)
		s[i]=tmp[i-n+x-1];
}
int main()
{
	re(n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i)
	{
		++cnt[s[i]-'a'];
		--cnt[t[i]-'a'];
	}
	for(int i=0;i<26;++i)
		if(cnt[i])
		{
			puts("-1");
			return 0;
		}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
			if(t[i]==s[j])
			{
				// cerr<<233<<endl;
				st[++top]=n-j;
				rev(j+1);
				st[++top]=1;
				rev(n);
				st[++top]=n;
				rev(1);
				break;
			}
		// for(int j=1;j<=n;++j)
			// putchar(s[j]);
		// puts("");
	}
	printf("%d\n",top);
	for(int i=1;i<=top;++i)
		printf("%d ",st[i]);
}
/*

YaZX

X(r)ZYa

aX(r)ZY

YZXa

*/