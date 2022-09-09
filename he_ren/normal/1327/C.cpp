#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",n+m+n*m-3);
	for(int i=1; i<n; ++i) putchar('U');
	for(int i=1; i<m; ++i) putchar('L');
	
	for(int i=1; i<=n; ++i)
	{
		char c = (i&1)? 'R': 'L';
		for(int j=1; j<m; ++j)
			putchar(c);
		if(i<n) putchar('D');
	}
	return 0;
}