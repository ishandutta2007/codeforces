#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d%s",&n,&Q,s+1);
	
	list<int> t;
	static int type[MAXN], f[MAXN], g[MAXN];
	for(int i=0; i<=n+1; ++i)
	{
		type[i] = s[i] >= '0' && s[i] <= '9';
		t.insert(t.end(), i);
		f[i] = g[i] = -1;
	}
	
	static array<int,10> sum[MAXN * 2], cursum;
	int curt = 0;
	
	auto it = t.begin();
	int dir = 1;
	stack<int> sta;
	while(t.size() > 2)
	{
		int pos = *it;
		while(sta.size() && sta.top() > pos)
			sum[g[sta.top()] = ++curt] = cursum,
			sta.pop();
		if(f[pos] == -1)
			sum[f[pos] = ++curt] = cursum,
			sta.push(pos);
		if(pos == 0 || pos == n+1){ it = next(t.begin()); dir = 1; continue;}
		
		char &c = s[pos];
		if(c == '>') dir = 1;
		if(c == '<') dir = -1;
		auto jt = dir == 1? next(it): prev(it);
		
		if(type[pos])
		{
			++cursum[c - '0'];
			if(c == '0') t.erase(it);
			else --c;
		}
		else if(!type[*jt]) t.erase(it);
		it = jt;
	}
	if(f[n+1] == -1)
		sum[f[n+1] = ++curt] = cursum,
		sta.push(n+1);
	while(sta.size())
		sum[g[sta.top()] = ++curt] = cursum,
		sta.pop();
	
	while(Q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		int tl = f[l], tr = min(f[r+1], g[l]);
		for(int i=0; i<=9; ++i) printf("%d ",sum[tr][i] - sum[tl][i]);
		putchar('\n');
	}
	return 0;
}