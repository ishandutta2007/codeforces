#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	vector<int> ans;
	
	bitset<1001> t;
	t[0] = 1;
	for(int i=n; i>=1; --i)
	{
		if(i <= d && t[d - i]) continue;
		ans.push_back(i);
		t |= t << i;
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}