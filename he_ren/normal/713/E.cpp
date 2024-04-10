#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n,m;
int a[MAXN];

int dp[MAXN];

bool chk(int len)
{
	for(int beg=1; beg<=2 && beg<=n; ++beg)
	{
		dp[beg] = beg == 1? a[1]: max(a[2], a[1] + len);
		if(beg == 2) dp[1] = a[1] + len;
		for(int i=beg+1; i<=n; ++i)
		{
			dp[i] = -inf;
			
			if(dp[i-1] >= a[i] - 1)
				chk_max(dp[i], a[i] + len);
			else if(dp[i-1] >= a[i] - len - 1)
				chk_max(dp[i], a[i]);
			
			if(i > 2 && dp[i-2] >= a[i] - len - 1)
				chk_max(dp[i], max(a[i], a[i-1] + len));
		}
		
		if(dp[n] >= min(m, a[beg] + m - len - 1))
			return 1;
	}
	return 0;
}

int main(void)
{
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int mxl = a[1] + m - a[n], pos = 1;
	for(int i=1; i<n; ++i)
		if(a[i+1] - a[i] > mxl)
			mxl = a[i+1] - a[i], pos = i+1;
	
	rotate(a+1, a+pos, a+n+1);
	for(int i=2; i<=n; ++i)
	{
		a[i] = a[i] - a[1] + 1;
		if(a[i] <= 0) a[i] += m;
	}
	a[1] = 1;
	
	int l = 0, r = mxl - 1;
	while(l < r)
	{
		int mid = (l+r)>>1;
		if(chk(mid)) r = mid;
		else l = mid+1;
	}
	
	printf("%d",l);
	return 0;
}