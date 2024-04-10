#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int a[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int rig[MAXN], lst[MAXN];
	for(int i=n; i>=1; --i)
	{
		rig[i] = lst[a[i]];
		if(rig[i] == 0) lst[a[i]] = i;
	}
	
	int i = 1;
	while(i<=n && rig[i] == 0) ++i;
	if(i>n) return printf("0"), 0;
	
	int ans = 0;
	int r = i;
	while(1)
	{
		ans += rig[i] - r - 1;
		
		pii mx = {0,0};
		for(int j=r+1; j<=rig[i]; ++j)
			mx = max(mx, {rig[j], j});
		if(mx.first <= rig[i])
		{
			i = rig[i] + 1;
			while(i<=n && rig[i] == 0) ++i;
			if(i > n) break;
			r = i; continue;
		}
		else r = rig[i], i = mx.second;
	}
	printf("%d",ans);
	return 0;
}