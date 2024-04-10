#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
int n,p[100005],up[100005],dn[100005];
bool used1[100005],used2[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&p[i]);
	for(int i=1;i<=n;++i)
	{
		if(p[i]>p[i-1])	up[i]=up[i-1]+1;
		else	up[i]=1;
	}
	for(int i=n;i;--i)
	{
		if(p[i]>p[i+1])	dn[i]=dn[i+1]+1;
		else	dn[i]=1;
	}
	int maxn=0;
	for(int i=1;i<=n;++i)	maxn=max(maxn,max(dn[i],up[i]));
	for(int i=1;i<=n;++i)
	{
		if(maxn==up[i])	used1[i]=true;
		if(maxn==dn[i])	used2[i]=true;
	}
	if(maxn==2)
	{
		puts("0");
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		if(used1[i] && used2[i])
		{
			if(i+maxn-1+maxn-1<=n && used1[i+maxn-1+maxn-1])	continue;
			if(i-maxn+1-maxn+1>=1 && used2[i-maxn+1-maxn+1])	continue;
			if((maxn&1))
			{
				++ans;
				continue;
			}
		}
	}
	printf("%d",ans>=2?0:ans);
	return 0;
}