#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

vector<int> get_bit(int x)
{
	vector<int> res;
	for(int i=0; i<30; ++i)
		if(bdig(x,i)) res.push_back(i);
	return res;
}

void solve(void)
{
	int u,v;
	scanf("%d%d",&u,&v);
	if(u > v){ printf("NO\n"); return;}
	if(u == v){ printf("YES\n"); return;}
	
	vector<int> x = get_bit(u), y = get_bit(v);
	while(x.back() == y.back()) x.pop_back(), y.pop_back();
	
	if(x.size() < y.size()){ printf("NO\n"); return;}
	x.resize(y.size());
	for(int i=0; i<(int)x.size(); ++i)
		if(x[i] > y[i]){ printf("NO\n"); return;}
	printf("YES\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}