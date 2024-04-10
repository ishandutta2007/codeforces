#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define maxn 100005
using namespace std;
ll inf = 1000001;
struct
{
	priority_queue <int, vector<int>, greater<int> > del, ins;
	void i(int a){ins.push(a);}
	void d(int a){del.push(a);}
	ll qmin()
	{
		while(!del.empty() && del.top() == ins.top()) del.pop(), ins.pop();
		if(ins.empty()) return inf;
		return ins.top();
	}
}h[maxn];
struct th
{
	ll tm, c, des;
	bool operator < (const th &a)const
	{
		return tm < a.tm;
	}
}in[maxn], out[maxn];
int n, m, k;
ll mns[maxn];
int main()
{
	inf *= 500000;
	scanf("%d%d%d", &n, &m, &k);
	int incnt = 0, outcnt = 0;
	for(int i = 0; i < m; i++)
	{
		int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if(!f) out[outcnt].tm = d, out[outcnt].c = c, out[outcnt].des = t, outcnt++;
		else in[incnt].tm = d, in[incnt].c = c, in[incnt].des = f, incnt++;
	}
	ll ans = 0;
	sort(in, in + incnt), sort(out, out + outcnt);
	for(int i = 0; i < maxn; i++) mns[i] = inf;
	for(int i = 1; i <= n; i++) ans += mns[i];

	int pl = 0;
	for(int i = 0; i < outcnt; i++) 
		h[out[i].des].i(out[i].c);
	for(int i = 1; i <= n; i++) ans += h[i].qmin();
	
	ll nans = ans;
	for(int i = 0; i < incnt; i++)
	{
		while(pl < outcnt && out[pl].tm <= in[i].tm + k)
			nans -= h[out[pl].des].qmin(), 
			h[out[pl].des].d(out[pl].c), 
			nans += h[out[pl].des].qmin(), 
			pl++;
		nans -= mns[in[i].des];
		mns[in[i].des] = min(mns[in[i].des], in[i].c);
		nans += mns[in[i].des];
		ans = min(ans, nans);
	}
	if(ans >= inf) ans = -1;
	printf("%I64d\n", ans);
	return 0;
}