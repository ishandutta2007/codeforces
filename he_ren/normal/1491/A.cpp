#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int a[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int cnt = 0;
	for(int i=1; i<=n; ++i) cnt += a[i];
	while(Q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t == 1) cnt -= a[x], a[x] ^= 1, cnt += a[x];
		else printf("%d\n",cnt >= x? 1: 0);
	}
	return 0;
}