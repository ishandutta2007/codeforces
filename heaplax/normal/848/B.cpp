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
#define N 100005
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
int n,w,h,g[N],p[N],t[N],ax[N],ay[N];
vector<int> x,y,s[N+N];
bool cmp(int i,int j)
{
	if(g[i]!=g[j])return g[i];
	else return g[i]?p[i]>p[j]:p[i]<p[j];
}
int main()
{
	re(n),re(w),re(h);
	for(int i=1;i<=n;++i)
	{
		re(g[i]),re(p[i]),re(t[i]);--g[i];
		s[p[i]-t[i]+N].push_back(i);
	}
	for(int i=1;i<N+N;++i)
		if(s[i].size())
		{
			x.clear();
			y.clear();
			for(int j=0;j<s[i].size();++j)
			{
				if(g[s[i][j]])y.push_back(p[s[i][j]]);
				else x.push_back(p[s[i][j]]);
			}
			sort(x.begin(),x.end());
			sort(y.begin(),y.end());
			sort(s[i].begin(),s[i].end(),cmp);
			for(int j=0;j<x.size();++j)
			{
				ax[s[i][j]]=x[j];
				ay[s[i][j]]=h;
			}
			for(int j=0;j<y.size();++j)
			{
				ax[s[i][j+x.size()]]=w;
				ay[s[i][j+x.size()]]=y[y.size()-j-1];
			}
		}
	for(int i=1;i<=n;++i)
		printf("%d %d\n",ax[i],ay[i]);
}
/*
8 10 8
1 1 10
1 4 13
1 7 1
1 8 2
2 2 0
2 5 14
2 6 0
2 6 1
*/