#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int h[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&h[i]);
	
	while(d)
	{
		for(int i=1; i<=n; ++i)
		{
			if(i == n){ printf("-1\n"); return;}
			if(h[i] < h[i+1])
			{
				++h[i]; --d;
				if(!d){ printf("%d\n",i); return;}
				break;
			}
		}
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}