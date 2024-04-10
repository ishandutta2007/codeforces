#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int d = 2e5;
const int MAXD = d + 5;

int a[MAXN], b[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i],&b[i]);
	
	auto chk = [&] (pii x,pii y)
	{
		return (ll)x.first * y.second > (ll)y.first * x.second;
	};
	
	pii ans = make_pair(0,1);
	vector<int> ansv;
	
	static pii p[MAXN];
	for(int k=1; k<=20; ++k)
	{
		for(int i=1; i<=d; ++i) p[i] = {0,i};
		for(int i=1; i<=n; ++i)
			p[a[i]].first += min(k, b[i]);
		sort(p+1,p+d+1);
		reverse(p+1,p+d+1);
		
		int cur = 0;
		for(int i=0; i<=k; ++i) cur += p[i].first;
		if(chk({cur, k}, ans))
		{
			ans = {cur, k};
			ansv.clear();
			for(int i=1; i<=k; ++i) ansv.push_back(p[i].second);
		}
	}
	
	for(int i=1; i<=d; ++i) p[i] = {0,i};
	for(int i=1; i<=n; ++i) p[a[i]].first += b[i];
	sort(p+1,p+d+1);
	reverse(p+1,p+d+1);
	
	int sum = 0;
	for(int i=1; i<=d; ++i)
	{
		sum += p[i].first;
		if(i > 20 && chk({sum, i}, ans))
		{
			ans = {sum, i};
			ansv.clear();
		}
	}
	
	if(ans.second > 20)
		for(int i=1; i<=ans.second; ++i)
			ansv.push_back(p[i].second);
	
	printf("%d\n",(int)ansv.size());
	for(int x: ansv) printf("%d ",x);
	return 0;
}