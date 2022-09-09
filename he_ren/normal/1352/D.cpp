#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int l=1, r=n, cur=0;
	int x=0, y=0, lx=0, ly=0;
	while(l<=r)
	{
		++cur;
		if(cur&1)
		{
			int now=0;
			while(l<=r && now<=ly) now+=a[l++];
			x+=now; lx=now;
		}
		else
		{
			int now=0;
			while(l<=r && now<=lx) now+=a[r--];
			y+=now; ly=now;
		}
	}
	printf("%d %d %d\n",cur,x,y);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}