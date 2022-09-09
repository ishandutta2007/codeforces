#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e2 + 5;

int Abs(int x){ return x<0? -x: x;}

int p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=(n>>1); ++i) scanf("%d",&p[i]);
	
	sort(p+1,p+(n>>1)+1);
	int ans1=0, ans2=0;
	for(int i=1; i<=(n>>1); ++i)
	{
		ans1 += Abs(p[i]-(i<<1));
		ans2 += Abs(p[i]-(i<<1)+1);
	}
	printf("%d",min(ans1,ans2));
	return 0;
}