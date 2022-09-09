#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e2 + 5;

int a[MAXN][MAXN];

int main(void)
{
	memset(a,-1,sizeof(a));
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i][i]);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j) a[i][j] = 0;
	
	for(int i=n; i>=1; --i)
	{
		int rem = a[i][i];
		vector<pii> q;
		q.push_back(make_pair(i, i));
		while(rem--)
		{
			int x = q.back().first, y = q.back().second;
			q.pop_back();
			a[x][y] = a[i][i];
			if(!a[x][y-1]) q.push_back(make_pair(x,y-1));
			if(!a[x+1][y]) q.push_back(make_pair(x+1,y));
		}
	}
	
	for(int i=1; i<=n; ++i, putchar('\n'))
		for(int j=1; j<=i; ++j)
			printf("%d ",a[i][j]);
	return 0;
}