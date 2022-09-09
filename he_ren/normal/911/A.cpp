#include<cstdio>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
#define make_pair mp
#define fir first
#define sec second
const int MAXN = 1e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

pii a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i].fir), a[i].sec=i;
	
	sort(a+1,a+n+1);
	int ans=n;
	for(int i=2; i<=n && a[i].fir==a[1].fir; ++i)
		chk_min(ans, a[i].sec - a[i-1].sec);
	printf("%d",ans);
	return 0;
}