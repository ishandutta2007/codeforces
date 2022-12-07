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
#define N 200001
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
int n,T;
struct node
{
	int a,t,num;
	bool operator < (const node& i)const
	{
		return t<i.t;
	}
}a[N];
bool check(int x)
{
	int last=T,have=0;
	for(int i=1;i<=n;++i)
		if(a[i].a>=x && last>=a[i].t)
			last-=a[i].t,++have;
	return have>=x;
}
int main()
{
	re(n),re(T);
	for(int i=1;i<=n;++i)
		re(a[i].a),re(a[i].t),a[i].num=i;
	sort(a+1,a+n+1);
	int l=0,r=n;
	while(l < r)
	{
		int mid=l+r+1>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n%d\n",l,l);
	int have=l;
	for(int i=1;i<=n;++i)
		if(a[i].a>=l && have)
		{
			--have;
			printf("%d ",a[i].num);
		}
	puts("");
}