#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100 + 5;

int a[MAXN*2];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=(n<<1); ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+(n<<1)+1);
	if(a[n]!=a[n+1]) printf("YES");
	else printf("NO");
	return 0;
}