#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	for(int i=1; i<=n/2; ++i)
		b[i*2] = a[i];
	for(int i=n/2+1,j=1; i<=n; ++i,j+=2)
		b[j] = a[i];
	
	int ans = 0;
	for(int i=2; i<n; ++i)
		if(b[i] < b[i-1] && b[i] < b[i+1])
			++ans;
	
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
		printf("%d ",b[i]);
	return 0;
}