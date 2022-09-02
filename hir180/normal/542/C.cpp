#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
int go[205];
int par[205],ran[205];
void init(){ for(int i=0;i<205;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
struct UF
{
	int par[205],ran[205];
	void init(){ for(int i=0;i<205;i++) par[i] = i; }
	int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
	void unite(int x,int y){
		x = find(x); y = find(y); if(x==y) return;
		if(ran[x] < ran[y]) par[x] = y;
		else{
			par[y] = x;
			if(ran[x] == ran[y]) ran[x]++;
		}
	}
	bool same(int x,int y){ return find(x)==find(y); }
}uf;
P rec(int v)
{
	vector<int>vt;
	for(int i=1;i<=n;i++) if(find(i) == v) vt.pb(i);
	uf.init();
	bool used[205]={}; int len=0;
	for(int i=0;i<vt.size();i++)
	{
		if(uf.same(vt[i],go[vt[i]]))
		{
			int cur = vt[i]; len = 0;
			do
			{
				used[cur] = true;
				cur = go[cur];
				len++;
			}while(cur != vt[i]); break;
		}else uf.unite(vt[i],go[vt[i]]);
	}
	int maxv = 0,ret = 0;
	for(int i=0;i<vt.size();i++)
	{
		int cur = vt[i];
		for(int j=0;;j++)
		{
			if(used[cur]){ maxv = j; break;} cur = go[cur];
		}
		ret = max(ret,maxv);
	}
	return mp(ret,len);
}
int main()
{
	cin >> n; init();
	for(int i=1;i<=n;i++)
	{
		cin >> go[i];
		unite(i,go[i]);
	}
	int limit = 0;
	ll v = 1;
	for(int i=1;i<=n;i++)
	{
		if(find(i) != i) continue;
		P p = rec(i);
		limit = max(limit,p.fi);
		v = v*1LL*p.sc / __gcd(v,1LL*p.sc);
	}
	ll res = v;
	while(limit > res) res += v;
	cout << res << endl;
}