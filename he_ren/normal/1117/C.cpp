#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

int sx,sy,tx,ty,n;
char s[MAXN];
int sumx[MAXN],sumy[MAXN];

inline ll dist(ll x,ll y,ll xx,ll yy){ return abs(x-xx) + abs(y-yy);}

inline bool chk(ll mid)
{
	ll x=sx,y=sy;
	
	ll tmp = mid/n;
	x += tmp*sumx[n];
	y += tmp*sumy[n];
	x += sumx[mid%n];
	y += sumy[mid%n];
	
	return dist(x,y,tx,ty) <= mid;
}

int main(void)
{
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	scanf("%d%s",&n,s+1);
	
	for(int i=1; i<=n; ++i)
	{
		sumx[i]=sumx[i-1];
		sumy[i]=sumy[i-1];
		if(s[i]=='U') ++sumy[i];
		if(s[i]=='D') --sumy[i];
		if(s[i]=='L') --sumx[i];
		if(s[i]=='R') ++sumx[i];
	}
	
	ll maxr = 1e17;
	ll l=0,r=maxr;
	while(l<r)
	{
		ll mid=(l+r)>>1ll;
		if(chk(mid)) r=mid;
		else l=mid+1;
	}
	
	if(l>=maxr) printf("-1");
	else printf("%lld",l);
	return 0;
}