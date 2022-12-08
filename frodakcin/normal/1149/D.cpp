#include <iostream>
#include <cstdio>

#include <vector>
#include <map>
#include <queue>

using namespace std;

const int MN = 70 + 5;
const int MM = 200 + 10;

using vi = vector<int>;
int N, M, A, B;
vi a[MN], b[MN];
#define pb push_back

using mii = map<int, int>;
int p[MN], s[MN];
int find(int a)
{
	if(a==p[a]) return a;
	return p[a]=find(p[a]);
}
bool merge(int a, int b)
{
	a=find(a), b=find(b);
	if(a==b)return 0;
	if(s[a]<s[b]) swap(a,b);
	p[b]=a, s[a]+=s[b], s[b]=0;
	return 1;
}
mii g;
int getg(int n)
{
	n=find(n);
	if(s[n]<=3) return -1;
	return g[n];
}
int getg2(int n) {int x = getg(n); return ~x?1<<x:0;}

int d[MN][1<<(MN>>2)];
bool v[MN][1<<(MN>>2)];
struct S
{
	int n, m;
	int D;
	int& gd(void) const {return d[n][m];}
	bool& gv(void) const {return v[n][m];}
	bool operator > (const S& o) const{return D < o.D;}
	bool operator < (const S& o) const{return o.D < D;}
};

bool mn(int& a, const int& b) {return !~a||b<a?a=b,1:0;}

using pq = priority_queue<S>;
pq q;

int main(void)
{
	scanf("%d%d%d%d", &N, &M, &A, &B);
	for(int i = 1;i <= N;i++)
		p[i] = i, s[i] = 1;
	for(int i = 0, x, y, z;i < M;i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		if(z==A) merge(x, y), a[x].pb(y), a[y].pb(x);
		else b[x].pb(y), b[y].pb(x);
	}
	for(int i = 1;i <= N;i++)
		if(p[i]==i&&s[i]>3)
			g.insert({i, g.size()});
	for(int i = 1;i <= N;i++)
		for(int j = (1<<g.size())-1;j>=0;j--)
			d[i][j]=-1;
	d[1][0] = 0;
	q.push({1, 0, 0});
	for(S n, t;!q.empty();q.pop())
	{
		n = q.top();
		if(n.gv()) continue;
		n.gv()=1;
		for(int x : a[n.n])
		{
			t = {x, n.m, n.D+A};
			if(!t.gv()&&mn(t.gd(), t.D))
				q.push(t);
		}
		for(int x : b[n.n])
			if(find(x)!=find(n.n)&&!(n.m&getg2(x)))
			{
				t = {x, n.m|getg2(n.n), n.D+B};
				if(!t.gv()&&mn(t.gd(), t.D))
					q.push(t);
			}
	}
	for(int i = 1;i <= N;i++)
	{
		int x = -1;
		for(int j = 0;j < 1<<g.size();j++)
			if(~d[i][j])
				mn(x, d[i][j]);
		printf("%d%c", x, " \n"[i==N]);
	}
	return 0;
}