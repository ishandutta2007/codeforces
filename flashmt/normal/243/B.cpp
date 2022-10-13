#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define reset(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,m,h,t,d[100100],iteration,flag1[100100],flag2[100100];
vector <int> a[100100];

void check(int H,int T)
{
	vector <int> head,tail;
	iteration++;
	rep(i,min(210,sz(a[H])))
	{
		int y=a[H][i];
		if (y!=T) flag1[y]=iteration;
	}
	rep(i,min(210,sz(a[T])))
	{
		int y=a[T][i];
		if (y!=H) flag2[y]=iteration;
	}
	
	rep(i,min(210,sz(a[H])))
	{
		int y=a[H][i];
		if (flag1[y]==iteration && flag2[y]!=iteration) head.pb(y);
	}
	
	rep(i,min(210,sz(a[T])))
	{
		int y=a[T][i];
		if (flag2[y]==iteration && flag1[y]!=iteration) tail.pb(y);
	}
	
	rep(i,min(210,sz(a[H])))
	{
		int y=a[H][i];
		if (flag1[y]==iteration && flag2[y]==iteration) 
		{
			if (sz(head)<h) head.pb(y);
			else tail.pb(y);
		}
	}

	if (sz(head)>=h && sz(tail)>=t)
	{
		puts("YES");
		cout << H << ' ' << T << endl;
		rep(i,h) cout << head[i] << ' '; puts("");
		rep(i,t) cout << tail[i] << ' '; puts("");
		exit(0);
	}
}

int main()
{
	int x[100100],y[100100];
	cin >> n >> m >> h >> t;
	for (int i=0;i<m;i++) cin >> x[i] >> y[i], a[x[i]].pb(y[i]), a[y[i]].pb(x[i]);
	for (int i=0;i<m;i++) check(x[i],y[i]), check(y[i],x[i]);
	puts("NO");
}