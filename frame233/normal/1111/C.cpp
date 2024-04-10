#include<cstdio>
#include<algorithm>
typedef long long ll;
ll n,k,a,b;
int pos[100005];
inline ll min(ll a,ll b){return a<b?a:b;}
ll solve(int l,int r)
{
	int num=std::upper_bound(pos+1,pos+k+1,r)-std::lower_bound(pos+1,pos+k+1,l);
	if(!num) return a;
	if(l==r) return b*num;
	int mid=(l+r)>>1;
	return min(solve(l,mid)+solve(mid+1,r),b*num*(r-l+1));
}
int main()
{
	scanf("%lld %lld %lld %lld",&n,&k,&a,&b);
	for(int i=1;i<=k;++i) scanf("%d",&pos[i]);
	std::sort(pos+1,pos+k+1);
	printf("%lld\n",solve(1,1<<n));
	return 0;
}