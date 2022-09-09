#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int sum = 0;
	for(int i=1; i<=n; ++i) sum ^= a[i];
	if(n%2 == 0 && sum) return printf("NO"), 0;
	
	printf("YES\n%d\n",(n-1)/2 * 2);
	for(int i=2; i+1<=n; i+=2)
		printf("%d %d %d\n",1,i,i+1);
	for(int i=2; i+1<=n; i+=2)
		printf("%d %d %d\n",1,i,i+1);
	return 0;
}