// luogu-judger-enable-o2
#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=200005;
int a[N];
int n,m;
inline bool cmp(const int &a,const int &b){return a>b;}
inline int max(const int &a,const int &b){return a>b?a:b;}
bool check(int x)
{
	ll ans=0;
	for(int i=1;i<=n;++i) ans+=max(0,a[i]-((i-1)/x));
	return ans>=m;
}
int main()
{
	ll sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),sum+=a[i];
	if(sum<m)
	{
		printf("-1\n");
		return 0;
	}
	std::sort(a+1,a+n+1,cmp);
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}