#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2.1e3 + 5;

int a[MAXN], pos[MAXN];

vector<int> ans;
inline void push_ans(int x)
{
	if(x == 1) return;
	ans.push_back(x);
	reverse(a+1,a+x+1);
	for(int i=1; i<=x; ++i) pos[a[i]] = i;
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		pos[a[i]] = i;
		if(i%2 != a[i]%2)
		{
			printf("-1\n");
			return;
		}
	}
	ans.clear();
	
	for(int i=n; i>1; i-=2)
	{
		push_ans(pos[i]);
		push_ans(pos[i-1] - 1);
		push_ans(pos[i-1] + 1);
		push_ans(3);
		push_ans(i);
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}