//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
const int mod = 1e9+7;
const int maxn = 100111;
int Tn, n;
vector<pair<int,int> > v;
vector<bool> ans;
bool pre[maxn], pre2[maxn];
int col[maxn];
void query()
{
	if (v.size()==0) return;
	printf("Q %d", int(v.size()));
	for (auto x : v) printf(" %d %d", x.FF, x.SS);
	puts("");
	fflush(stdout);
	static char s[maxn];
	scanf("%s", s);
	ans.clear();
	for (int i=0; i<v.size(); i++) ans.PB(s[i]-'0');
}
vector<int> a;
void solve()
{
	scanf("%d", &n);
	if (n==-1) exit(0);
	v.clear();
	for (int i=2; i<=n; i+=2) v.PB(MP(i, i-1));
	query();
	for (int i=0; i<v.size(); i++) pre[v[i].FF] = ans[i];
	v.clear();
	for (int i=3; i<=n; i+=2) v.PB(MP(i, i-1));
	query();
	for (int i=0; i<v.size(); i++) pre[v[i].FF] = ans[i];
	
	a.clear();
	for (int i=1; i<=n; i++)
	{
		if (i==1||pre[i]==0) a.PB(i);
	}
	
	v.clear();
	for (int i=2; i<a.size(); i+=4) v.PB(MP(a[i], a[i-2]));
	for (int i=3; i<a.size(); i+=4) v.PB(MP(a[i], a[i-2]));
	query();
	for (int i=0; i<v.size(); i++) pre2[v[i].FF] = ans[i];
	v.clear();
	for (int i=4; i<a.size(); i+=4) v.PB(MP(a[i], a[i-2]));
	for (int i=5; i<a.size(); i+=4) v.PB(MP(a[i], a[i-2]));
	query();
	for (int i=0; i<v.size(); i++) pre2[v[i].FF] = ans[i];
	
	memset(col, -1, sizeof(col));
	int cur = -1, pre = -1;
	for (int i=0; i<a.size(); i++)
	{
		int &c = col[a[i]];
		if (i==0)
		{
			c = 0;
		}
		else if (i==1)
		{
			c = 1;
		}
		else
		{
			if (pre2[a[i]]) c = pre;
			else
			{
				c = 0;
				while (c==pre||c==cur) c++;
			}
		}
		pre = cur;
		cur = c;
	}
	int c = -1;
	vector<int> V[3];
	for (int i=1; i<=n; i++)
	{
		if (col[i]!=-1) c = col[i];
		assert(c!=-1);
		V[c].PB(i);
	}
	printf("A %d %d %d\n", int(V[0].size()), int(V[1].size()), int(V[2].size()));
	for (int i=0; i<3; i++)
	{
		for (auto x : V[i]) printf("%d ", x);
		puts("");
	}
	fflush(stdout);
}
int main()
{
	scanf("%d", &Tn);
	while (Tn--)
	{
		solve();
	}
	return 0;
}