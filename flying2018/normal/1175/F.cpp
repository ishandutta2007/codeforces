#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ull unsigned long long
#define N 300010
using namespace std;
ull h[N],base[N],g[N];
int num[N],n;
int work(int l)
{
	int maxn=1,res=0;
	for(int i=l+1;i<=n;i++)
	{
		if(num[i]==1) break;
		maxn=max(maxn,num[i]);
		if(i>=maxn && i<=l+maxn-1 && g[maxn]==(h[i]^h[i-maxn])) res++;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	base[0]=1;
	for(int i=1;i<=n;i++) base[i]=base[i-1]*233+rand()%3,g[i]=g[i-1]^base[i];
	int ans=0;
	for(int i=1;i<=n;i++) h[i]=h[i-1]^base[num[i]];
	for(int i=1;i<=n;i++)
	if(num[i]==1) ans+=work(i)+1;
	reverse(num+1,num+n+1);
	for(int i=1;i<=n;i++) h[i]=h[i-1]^base[num[i]];
	for(int i=1;i<=n;i++)
	if(num[i]==1) ans+=work(i);
	printf("%d\n",ans);
	return 0;
}