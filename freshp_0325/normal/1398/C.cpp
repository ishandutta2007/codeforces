#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
0

*/
int a[100005],n,t,sum[100005];
map<int,LL> maplive;
int main(){
	scanf("%d",&t);
	while(t-->0)
	{
		maplive.clear();
		scanf("%d",&n);
		LL ans=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%1d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			++maplive[sum[i]-i];
		}
		for(map<int,LL>::iterator it=maplive.begin();it!=maplive.end();++it)
		{
			pair<int,LL> s=*it;
			if(s.first==0)	ans+=s.second*(s.second+1)/2;
			else	ans+=s.second*(s.second-1)/2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 -1 -1 -1 -1 4
cnt[100005]=1
cnt[99999]=4;
*/