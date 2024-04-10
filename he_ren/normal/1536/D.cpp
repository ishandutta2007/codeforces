#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int b[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	stack<int> lef, rig;
	int x = 0, y = 0;
	for(int i=2; i<=n; ++i)
	{
		int cur = b[i - 1];
		if(b[i] == cur){ ++x; ++y; continue;}
		if(b[i] < cur)
		{
			if(lef.size() && b[i] < lef.top()){ printf("NO\n"); return;}
			if(lef.size() && b[i] == lef.top())
			{
				rig.push(cur); lef.pop();
				x += 2;
			}
			else
				rig.push(cur), ++x;
		}
		else
		{
			if(rig.size() && b[i] > rig.top()){ printf("NO\n"); return;}
			if(rig.size() && b[i] == rig.top())
			{
				lef.push(cur); rig.pop();
				y += 2;
			}
			else lef.push(cur), ++y;
		}
	}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}