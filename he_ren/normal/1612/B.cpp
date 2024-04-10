#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

void solve(void)
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	
	if(a > b)
	{
		if(a != b + 1 || b != n / 2)
			printf("-1\n");
		else
		{
			for(int i=n; i>=1; --i)
				printf("%d ",i);
			printf("\n");
		}
		return;
	}
	
	vector<int> lef(1,a), rig(1,b), p;
	for(int i=1; i<=n; ++i)
	{
		if(i == a || i == b) continue;
		if(i > b) lef.push_back(i);
		else if(i < a) rig.push_back(i);
		else p.push_back(i);
	}
	int x = lef.size(), y = rig.size(), z = p.size();
	
	if(z < abs(y - x))
	{
		printf("-1\n");
		return;
	}
	
	while(p.size())
	{
		if(lef.size() > rig.size()) rig.push_back(p.back());
		else lef.push_back(p.back());
		p.pop_back();
	}
	
	for(int t: lef) printf("%d ",t);
	for(int t: rig) printf("%d ",t);
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}