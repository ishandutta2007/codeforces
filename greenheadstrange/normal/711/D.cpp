#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define maxn 200005
using namespace std;
long long nx[maxn];
long long dep[maxn],lavi[maxn];
long long cnt[maxn];
long long cnts=0;
long long mode=1000000007;
long long outside=0;
void dfs(long long a,long long b)
{
	lavi[a]=b;	
	if(lavi[nx[a]] && lavi[nx[a]]!=b) return ;
	if(lavi[nx[a]]!=b) dep[nx[a]]=dep[a]+1, dfs(nx[a],b);
	else
		cnt[++cnts]=dep[a]-dep[nx[a]]+1;
}
long long power[maxn];
long long n;
int main()
{
	memset(dep,0,sizeof(dep));
	memset(lavi,0,sizeof(lavi));
	power[0]=1;
	for(long long i=1;i<maxn;i++) power[i]=2*power[i-1],power[i]%=mode;
	 scanf("%I64d",&n);
	 for(long long i=1;i<=n;i++) scanf("%I64d",&nx[i]);
	 for(long long i=1;i<=n;i++)
	 {
	 	if(!dep[i]) dfs(i,i);
	 }
	 outside=n;
	 for(long long i=1;i<=cnts;i++) outside-=cnt[i];
	 long long ans=power[outside];
	 for(long long i=1;i<=cnts;i++) ans*=(power[cnt[i]]-2),ans%=mode;
	 printf("%I64d\n",ans);
	return 0;
}