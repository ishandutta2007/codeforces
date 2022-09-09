#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long ll;
const int MAXN = 2e3 + 5;
using namespace std;

struct Sum
{
	ll s;
	int x,y;
}sa[MAXN*MAXN],sb[MAXN*MAXN];
int acnt=0,bcnt=0;
inline bool cmp(const Sum &x,const Sum &y){ return x.s<y.s;}

int a[MAXN],b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	ll tmp=0;
	for(int i=1; i<=n; ++i) tmp+=a[i];
	for(int i=1; i<=m; ++i) tmp-=b[i];
	if(!tmp)
	{
		printf("0\n0\n");
		return 0;
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<i; ++j)
			sa[++acnt] = (Sum){((ll)a[i]+a[j])*2, i,j};
	}
	for(int i=1; i<=m; ++i)
	{
		for(int j=1; j<i; ++j)
			sb[++bcnt] = (Sum){((ll)b[i]+b[j])*2, i,j};
	}
	
	sort(sa+1,sa+acnt+1,cmp);
	sort(sb+1,sb+bcnt+1,cmp);
	
	int ans1=0,ans2=0;
	ll ans = abs(tmp);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(abs((ll)2*a[i]-tmp-(ll)2*b[j]) < ans)
			{
				ans = abs((ll)2*a[i]-tmp-(ll)2*b[j]);
				ans1 = -i;
				ans2 = -j;
			}
		}
	
	for(int i=1; i<=acnt; ++i)
	{
		sa[i].s-=tmp;
		int j = lower_bound(sb+1,sb+bcnt+1, sa[i], cmp)-sb;
		if(j>0 && j<=bcnt && abs(sa[i].s-sb[j].s) < ans)
		{
			ans=abs(sa[i].s-sb[j].s);
			ans1=i; ans2=j;
		}
		
		--j;
		if(j>0 && j<=bcnt && abs(sa[i].s-sb[j].s) < ans)
		{
			ans=abs(sa[i].s-sb[j].s);
			ans1=i; ans2=j;
		}
	}
	
	cout<<ans<<endl;
	if(ans1 < 0)
	{
		printf("1\n");
		printf("%d %d\n",-ans1,-ans2);
	}
	else if(ans1 > 0)
	{
		printf("2\n");
		printf("%d %d\n",sa[ans1].x,sb[ans2].x);
		printf("%d %d\n",sa[ans1].y,sb[ans2].y);
	}
	else printf("0");
	return 0;
}