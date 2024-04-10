#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAXN = 1000005;

int T,n,len;
int a[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&len);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		db L = 0,R = len,sl = 1,sr = 1,ans = 0;
		int l = 1,r = n;
		while (l <= r)
		{
			db t1 = (a[l] - L) / sl,t2 = (R - a[r]) / sr;
			if (t1 < t2)
			{
				ans += t1;
				L += sl * t1;
				R -= sr * t1;
				sl++;
				l++;
			}
			else
			{
				ans += t2;
				L += sl * t2;
				R -= sr * t2;
				sr++;
				r--;
			}
		}
		ans += (R - L) / (sl + sr);
		printf("%.10lf\n",ans);
	}
	return 0;
}