#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<pii> getres(int n,int d)
{
	vector<pii> res;
	res.emplace_back(n-1,d);
	if(d) res.emplace_back(0,~d&(n-1));
	for(int i=1; i<n/2; ++i) if(i != d && i != (~d&(n-1)))
		res.emplace_back(i,~i&(n-1));
	return res;
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	if(d != n-1)
	{
		auto res = getres(n,d);
		for(pii x: res) printf("%d %d\n",x.first,x.second);
	}
	else
	{
		if(n == 4) printf("-1\n");
		else
		{
			printf("%d %d\n",n-1,n-2);
			printf("%d %d\n",1,3);
			printf("%d %d\n",0,n-4);
			for(int i=0; i<n/2; ++i)
			{
				if(i == n-1 || i == n-2 || i == 1 || i == 3 || i == 0 || i == n-4) continue;
				printf("%d %d\n",i,n-1-i);
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