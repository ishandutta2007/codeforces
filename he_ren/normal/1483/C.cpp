#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int h[MAXN], b[MAXN];
ll val[MAXN], f[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&h[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	multiset<ll> t;
	stack<int> sta;
	for(int i=1; i<=n; ++i)
	{
		val[i] = f[i-1];
		while(sta.size() && h[sta.top()] > h[i])
		{
			int j = sta.top();
			t.erase(t.find(val[j] + b[j]));
			val[i] = max(val[i], val[j]);
			sta.pop();
		}
		t.insert(val[i] + b[i]);
		sta.push(i);
		
		f[i] = *t.rbegin();
	}
	printf("%lld",f[n]);
	return 0;
}