#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int n,d;
int a[MAXN];

bool chk(int k)
{
	static int sum[MAXN], mn[MAXN];
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + (a[i] >= k? 1: -1);
		mn[i] = min(mn[i-1], sum[i]);
		
		if(i>=d && mn[i-d] < sum[i]) return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int l = 1, r = n;
	while(l<r)
	{
		int mid = (l+r+1)>>1;
		if(chk(mid)) l = mid;
		else r = mid-1;
	}
	printf("%d",l);
	return 0;
}