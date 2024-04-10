#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,siz[100005],minn[100005],maxn[100005];
long long ans;
bool f[100005];
vector<int> vec[100005];
vector<int> tmp1,tmp2;
bool cmp1(int x,int y)
{
	return minn[x]<minn[y];
}
bool cmp2(int x,int y)
{
	return maxn[x]<maxn[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&siz[i]);
		minn[i]=1e9+1;
		for(int j=1;j<=siz[i];j++)
		{
			int x;
			scanf("%d",&x);
			vec[i].push_back(x);
			if(j!=1) if(x>vec[i][j-2]) f[i]=true;
			maxn[i]=max(maxn[i],x);
			minn[i]=min(minn[i],x);
		}
		if(!f[i]) tmp1.push_back(i);
	}
	int s=tmp1.size(),now=0;
	tmp2=tmp1;
	sort(tmp1.begin(),tmp1.end(),cmp1);
	sort(tmp2.begin(),tmp2.end(),cmp2);
	for(int i=0;i<s;i++)
	{
		if(now==s) break;
		while(minn[tmp1[now]]<maxn[tmp2[i]]) 
		{
			now++;
			if(now==s) break;
		}
		ans+=s-now;
//		printf("%d %d %d %d\n",i,tmp1[now],minn[tmp1[now]],maxn[tmp2[i]]);
	}
	printf("%lld\n",(long long)n*(long long)n-ans);
}