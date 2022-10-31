#include<cstdio>
#include<algorithm>
#define int long long
struct node{
	int val,id;
}a[200005];
int val[200005];
bool used[200005];
inline bool cmp(const node &a,const node &b){return a.val>b.val;}
signed main()
{
	int n,m,k,ans=0;
	scanf("%lld %lld %lld",&n,&m,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&val[i]),a[i]=(node){val[i],i};
	std::sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m*k;++i) ans+=a[i].val,used[a[i].id]=1;
	printf("%lld\n",ans);
	int cur=0;
	for(int i=1;i<=n;)
	{
		if(cur==k-1)
		{
			return 0;
		}
		int cnt=0;
		for(int j=i;j<=n;++j)
		{
			
			if(used[j])
			{
				++cnt;
				if(cnt==m)
				{
					i=j+1;
					break;
				}
			}
			if(j==n)
			{
				return 0;
			}
		}
		++cur;
		printf("%lld ",i-1);
	}
	return 0;
}