#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;

int a[MAXN];
bool f[MAXN];
int pre[MAXN];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i)
	{
		int l = lower_bound(a+1,a+i+1, a[i] - d) - a, r = i - m + 1;
		if(l <= r && pre[r - 1] >= l - 1)
			f[i] = 1, pre[i] = i;
		else
			pre[i] = pre[i-1];
	}
	if(f[n]) printf("YES");
	else printf("NO");
	return 0;
}