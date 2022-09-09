#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXA = 1e2 + 5;

inline bool chk(int x,int d)
{
	while(x)
	{
		if(x%10 == d) return 1;
		x /= 10;
	}
	return 0;
}

bool f[15][MAXA];

void solve(void)
{
	int Q,d;
	scanf("%d%d",&Q,&d);
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		if(x%d == 0){ printf("YES\n"); continue;}
		if(10 * d <= x){ printf("YES\n"); continue;}
		if(f[d][x]) printf("YES\n");
		else printf("NO\n");
	}
}

int main(void)
{
	for(int k=2; k<=9; ++k)
		for(int i=1; i<=100; ++i)
		{
			if(chk(i,k)){ f[k][i] = 1; continue;}
			for(int j=1; j<i; ++j)
				if(f[k][j] && f[k][i-j]){ f[k][i] = 1; break;}
		}
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}