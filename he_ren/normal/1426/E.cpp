#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int calc(int &x,int &y)
{
	int mn = min(x,y);
	x-=mn; y-=mn;
	return mn;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	int a[4], b[4];
	for(int i=0; i<3; ++i) scanf("%d",&a[i]);
	for(int i=0; i<3; ++i) scanf("%d",&b[i]);
	
	int ans = n;
	
	int p[4] = {0,1,2,3};
	do
	{
		int x[4], y[4];
		
		int all = (1<<3) - 1;
		for(int mask=0; mask<=all; ++mask)
		{
			for(int i=0; i<3; ++i)
				x[i] = a[i],
				y[i] = b[i];
			
			int res = 0;
			for(int i=0; i<3; ++i)
			{
				int k = p[i];
				if((mask>>k)&1)
				{
					calc(y[k], x[(k+1)%3]);
					calc(y[k], x[k]);
				}
				else
				{
					calc(y[k], x[k]);
					calc(y[k], x[(k+1)%3]);
				}
			}
			for(int i=0; i<3; ++i)
				res += calc(x[i], y[(i+1)%3]);
			
			ans = min(ans, res);
		}
	}while(next_permutation(p,p+3));
	
	printf("%d %d",ans,min(a[0],b[1]) + min(a[1],b[2]) + min(a[2],b[0]));
	return 0;
}