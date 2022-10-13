
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
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int n,f[111][10010],a[10010],m,g[10010];

int main()
{
	int s,x;
	cin >> n >> m;
	for (int k=1;k<=n;k++)
	{
		for (int i=0;i<=m;i++) f[k][i]=f[k-1][i];
		cin >> s;
		for (int i=1;i<=s;i++) cin >> x, a[i]=a[i-1]+x;
		for (int i=1;i<=s;i++)
		{
			g[i]=0;
			for (int j=0;j<=i;j++) g[i]=max(g[i],a[i-j]+a[s]-a[s-j]);
			for (int j=0;j+i<=m;j++) f[k][j+i]=max(f[k][j+i],f[k-1][j]+g[i]);
		}
	}
	int ans=0;
	for (int i=0;i<=m;i++) ans=max(ans,f[n][i]);
	cout << ans << endl;
}