//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;
const int maxn = 200111;
int n, m;
int a[maxn];
vector<pair<int,int> > v;
int tab[maxn];
void add(int x)
{
	for (int i=x; i<maxn; i+=i&(-i)) tab[i]++;
}
int query(int x)
{
	int ans = 0;
	for (int i=x; i; i-=i&(-i)) ans += tab[i];
	return ans;
}
int query_kth(int k)
{
	int l=1, r=n;
	while (l<=r)
	{
		int m = (l+r)/2;
		if (query(m)<k) l = m+1;
		else r = m-1;
	}
	return l;
}
vector<pair<int,int> > qv[maxn];
int qans[maxn];
int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]), v.PB(MP(-a[i], i));
	sort(v.begin(), v.end());
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		int k, p;
		scanf("%d%d", &k, &p);
		qv[k].PB(MP(p,i)); 
	}
	for (int i=1; i<=n; i++)
	{
		add(v[i-1].SS);
		for (auto p : qv[i])
		{
			qans[p.SS] = a[query_kth(p.FF)];
		}
	}
	for (int i=1; i<=m; i++) printf("%d\n", qans[i]);
	return 0;
}