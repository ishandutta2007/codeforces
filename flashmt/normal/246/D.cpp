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

int n,c[100100];
set <int> a[100100];

int main()
{
	int m,x,y,minColor=100100;
	cin >> n >> m;
	fr(i,1,n) cin >> c[i], minColor=min(minColor,c[i]);
	while (m--)
	{
		cin >> x >> y;
		if (c[x]==c[y]) continue;
		a[c[x]].insert(c[y]);
		a[c[y]].insert(c[x]);
	}
	
	int ans=0,color;
	fr(i,1,100000)
		if (sz(a[i])>ans)
			ans=sz(a[i]), color=i;
			
	if (!ans) color=minColor;
			
	cout << color << endl;
}