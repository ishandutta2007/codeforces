#include<bits/stdc++.h>
using namespace std;
const int MAXQ = 5e5 + 5;

int a[MAXQ], n = 0;
long long sum[MAXQ];

int main(void)
{
	int Q;
	scanf("%d",&Q);
	
	double ans = 0;
	for(int i=1; i<=Q; ++i)
	{
		int oper;
		scanf("%d",&oper);
		if(oper == 2)
			printf("%.7lf\n",ans);
		else
		{
			int x;
			scanf("%d",&x);
			if(n >= 1)
			{
				int l = 0, r = n - 1;
				while(l < r)
				{
					int mid = (l+r+1)/2;
					double val1 = (double)(sum[mid] + x) / (mid+1);
					double val2 = (double)(sum[mid+1] + x) / (mid+2);
					if(val1 > val2)
						l = mid;
					else
						r = mid - 1;
				}
				
				double val = (double)(sum[l+1] + x) / (l+2);
				ans = max(ans, x - val);
			}
			a[++n] = x;
			sum[n] = sum[n-1] + a[n];
		}
	}
	return 0;
}