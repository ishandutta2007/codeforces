#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;

int a[MAXN];

vector<int> b[MAXN];
bool del[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) del[i] = 0;
	
	b[1] = vector<int>(1, 1);
	stack<int> sta;
	sta.push(1);
	for(int i=2; i<=n; ++i)
	{
		if(a[i] == 1)
		{
			b[i] = b[sta.top()];
			b[i].push_back(1);
			sta.push(i);
			continue;
		}
		
		while(b[sta.top()].back() != a[i] - 1)
			sta.pop();
		b[i] = b[sta.top()];
		++b[i].back();
		sta.pop();
		sta.push(i);
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<(int)b[i].size(); ++j)
			printf("%d%c",b[i][j],".\n"[j+1 == (int)b[i].size()]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}