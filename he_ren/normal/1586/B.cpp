#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> del(n+1, 0);
	for(int i=1; i<=m; ++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		del[b] = 1;
	}
	
	for(int i=1; i<=n; ++i)
		if(!del[i])
		{
			for(int j=1; j<=n; ++j)
				if(j != i)
					printf("%d %d\n",i,j);
			return;
		}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}