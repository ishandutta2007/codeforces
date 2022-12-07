#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>

#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v

void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
int n,m,ans,out;
vector<int> lc[101];
int main()
{
	re(n),re(m);
	for(int i=1,k,f;i<=m;++i)
	{
		re(k),re(f);
		lc[f].push_back(k);
	}
	for(int i=1;i<=100;++i)sort(lc[i].begin(),lc[i].end());
	for(int i=1;i<=100;++i)
	{
		bool ok=1;
		for(int j=1;j<=100;++j)
			if(lc[j].size() && !(lc[j][0]>=i*(j-1)+1 && lc[j][lc[j].size()-1]<=i*j))
				ok=0;
		if(ok)
		{
			if(!out)out=(n-1)/i+1;
			else if(out != (n-1)/i+1)
			{
				puts("-1");
				return 0;
			}
		}
	}
	if(!out)puts("-1");
	else printf("%d\n",out);
}