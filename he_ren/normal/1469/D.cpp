#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> ans;
inline void push_ans(int x,int y){ ans.push_back(make_pair(x,y));}

void solve(void)
{
	int n;
	scanf("%d",&n);
	ans.clear();
	
	while(n > 3)
	{
		int k = sqrt(n) + 0.5;
		for(int i=k+1; i<n; ++i) push_ans(i, n);
		
		int m = n;
		while(m > 1) push_ans(n,k), m = (m + k - 1) / k;
		n = k;
	}
	if(n == 3) push_ans(3, 2), push_ans(3, 2);
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}