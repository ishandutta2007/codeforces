#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans=INT_MAX;
map<int,int>mp;
int ask(int x)
{
	if(mp.find(x)!=mp.end())
		return mp[x];
	printf("? %d\n",x);
	fflush(stdout);
	int v;
	scanf("%d",&v);
	if(v)
		ans=min(ans,x*v);
	return mp[x]=v;
}
int main()
{
	scanf("%d",&n);
	l=0,r=1e7;
	while(r-l>1)
	{
		int md=l+r>>1;
		if(ask(md)==1)
			r=md;
		else
			l=md;
	}
	r--;
	for(int i=2;i<=n;i++)
		if(r/i)
			ask(r/i);
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}