#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

map<array<int,3>,int> mp;
int ask(int i,int j,int k)
{
	array<int,3> t = {i,j,k};
	sort(t.begin(), t.end());
	if(mp.find(t) != mp.end()) return mp[t];
	printf("? %d %d %d\n",i,j,k);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return mp[t] = res;
}
void answer(int i,int j)
{
	printf("! %d %d\n",i,j);
	fflush(stdout);
}

void solve(void)
{
	int n;
	scanf("%d",&n);
	mp.clear();
	
	int mx = -1, mxpos = 3;
	for(int i=3; i<=n; ++i)
	{
		int t = ask(1, 2, i);
		if(t > mx) mx = t, mxpos = i;
	}
	
	vector<pii> a;
	for(int i=2; i<=n; ++i) if(i != mxpos)
	{
		int t = ask(1, i, mxpos);
		a.emplace_back(t, i);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	
	vector<int> vec = {1, 2, mxpos};
	for(pii x: a) if(x.second != 2)
	{
		vec.push_back(x.second);
		break;
	}
	
	array<int,3> t = {-1, -1, -1};
	for(int x: vec) for(int y: vec) if(x != y)
	{
		int cur = -1;
		for(int z: vec) if(z != x && z != y)
		{
			int k = ask(x, y, z);
			if(cur != -1 && cur != k) cur = -2;
			else cur = k;
		}
		if(cur < 0) continue;
		t = max(t, array<int,3>{cur, x, y});
	}
	
	answer(t[1], t[2]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}