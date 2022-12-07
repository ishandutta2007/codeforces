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
#define N 1000001
#define LL long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
LL sum;
int n,a[N];
int s[N];
int ask(int x)
{
	int res=0;
	for(;x;x-=x&-x)
		res+=s[x];
	return res;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)
	{
		re(a[i]);
		sum+=ask(n)-ask(a[i]);
		for(int x=a[i];x<=n;x+=x&-x)
			s[x]++;
	}
	puts((n&1)^(sum&1)?"Um_nik":"Petr");
}