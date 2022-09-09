#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int a[MAXN];
int pos[MAXN], f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]), a[n+i] = a[n+n+i] = a[i];
	int nn = n * 3;
	
	static pii sta[MAXN];
	int top = 0;
	sta[0] = make_pair(0, nn + 1);
	for(int i=nn; i>=1; --i)
	{
		pos[i] = (lower_bound(sta+1,sta+top+1,make_pair((a[i] + 1) / 2, 0)) - 1) -> second;
		while(sta[top].first >= a[i]) --top;
		sta[++top] = make_pair(a[i], i);
	}
	
	top = 0;
	int curf = nn + 1;
	for(int i=nn; i>=1; --i)
	{
		while(top && sta[top].first >= pos[i]) --top;
		int to = sta[top].second - 1;
		
		if(to >= pos[i]) curf = pos[i] - 1;
		sta[++top] = make_pair(pos[i], i);
		
		f[i] = curf;
	}
	
	for(int i=1; i<=n; ++i)
		printf("%d ",f[i]>nn? -1: f[i] - i + 1);
	return 0;
}