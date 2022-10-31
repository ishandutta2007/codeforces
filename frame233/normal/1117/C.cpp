#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long ll;
const int N=100005;
char s[N];
ll x1,y1,x2,y2,n;
ll d_x[N],d_y[N];
inline ll abs(ll a){return a>0?a:-a;}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
bool check(ll t)
{
	ll cnt=t/n;
	ll dx=cnt*d_x[n]+d_x[t-cnt*n],dy=cnt*d_y[n]+d_y[t-cnt*n];
	return (abs(x1+dx-x2)+abs(y1+dy-y2))<=t;
}
int main()
{
	scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
	scanf("%lld %s",&n,s+1);
	if(x1==x2&&y1==y2)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		d_x[i]=d_x[i-1]+(s[i]=='L'?-1:s[i]=='R'?1:0);
		d_y[i]=d_y[i-1]+(s[i]=='D'?-1:s[i]=='U'?1:0);
	}
	ll l=1,r=0x7ffffffffffffff,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(l<0x7ffffffffffffff) printf("%lld\n",l);
	else printf("-1\n");
	return 0;
}