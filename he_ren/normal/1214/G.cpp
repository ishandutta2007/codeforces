#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e3 + 5;
const int MAXM = 2e3 + 5;

inline int read(void)
{
	int res=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c=getchar();
	return res;
}
inline void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10 + '0');
}

bitset<MAXM> a[MAXN];
int b[MAXN];

int main(void)
{
	int n = read(), m = read(), Q = read();
	
	set<pii> t;
	set<int> valid;
	static bool isvalid[MAXN];
	for(int i=1; i<=n; ++i) t.emplace(0, i);
	auto chk = [&] (int i,int j)
	{
		if(i == -1 || j == -1) return false;
		if(b[i] < b[j]) swap(i,j);
		return (a[i] & a[j]) != a[j];
	};
	auto erase = [&] (int i)
	{
		auto it = t.find({b[i], i});
		t.erase(it++);
		int x,y;
		x = it == t.begin()? -1: prev(it) -> second;
		y = it == t.end()? -1: it -> second;
		
		if(isvalid[i])
			valid.erase(i), isvalid[i] = 0;
		if(x != -1 && isvalid[x])
			valid.erase(x), isvalid[x] = 0;
		if(chk(x,y))
			valid.insert(x), isvalid[x] = 1;
	};
	auto insert = [&] (int i)
	{
		auto it = t.emplace(b[i], i).first;
		int x,y;
		x = it == t.begin()? -1: prev(it) -> second;
		y = next(it) == t.end()? -1: next(it) -> second;
		
		if(x != -1 && isvalid[x])
			valid.erase(x), isvalid[x] = 0;
		if(chk(x,i))
			valid.insert(x), isvalid[x] = 1;
		if(chk(i,y))
			valid.insert(i), isvalid[i] = 1;
	};
	
	static bitset<MAXM> pre[MAXM];
	for(int i=1; i<=m; ++i)
		pre[i] = pre[i-1] << 1,
		pre[i][1] = 1;
	
	while(Q--)
	{
		int x = read(), l = read(), r = read();
		erase(x);
		a[x] = a[x] ^ pre[r] ^ pre[l-1];
		b[x] = a[x].count();
		insert(x);
		
		if(!valid.size()){ printf("-1\n"); continue;}
		
		int u = *valid.begin(), v = next(t.find({b[u], u})) -> second;
		assert(chk(u, v));
		
		bitset<MAXM> dif = a[u] ^ a[v];
		bitset<MAXM> p = dif & a[u], q = dif ^ p;
		int yl = p._Find_first();
		int yr = q._Find_first();
		if(yl > yr) swap(yl, yr);
		if(u > v) swap(u, v);
		
		write(u); putchar(' ');
		write(yl); putchar(' ');
		write(v); putchar(' ');
		write(yr); putchar('\n');
	}
	return 0;
}