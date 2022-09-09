#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 4e4 + 5;

int n,m;
int a[MAXN],b[MAXN];
vector<int> c,d;

ll calc(int x,int y)
{
	ll cnt1=0,cnt2=0;
	for(int i=0; i<(int)c.size(); ++i)
		if(c[i]>=x) cnt1 += c[i]-x+1;
	for(int i=0; i<(int)d.size(); ++i)
		if(d[i]>=y) cnt2 += d[i]-y+1;
	return cnt1*cnt2;
}

int main(void)
{
	ll k;
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && a[j]==a[i]) ++j;
		if(a[i]) c.push_back(j-i);
	}
	
	for(int i=1,j=1; i<=m; i=j)
	{
		while(j<=m && b[j]==b[i]) ++j;
		if(b[i]) d.push_back(j-i);
	}
	
	int sk = sqrt(k);
	ll ans=0;
	for(int i=1; i<=sk; ++i)
		if(!(k%i))
		{
			if(k/i==i) ans += calc(i,i);
			else ans += calc(i,k/i) + calc(k/i,i);
		}
	printf("%lld",ans);
	return 0;
}