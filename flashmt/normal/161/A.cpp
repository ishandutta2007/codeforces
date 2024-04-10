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

int n,m,a[100100],b[100100],x,y,ans,rx[100100],ry[100100];

int main()
{
	cin >> n >> m >> x >> y;
	rep(i,n) cin >> a[i];
	rep(i,m) cin >> b[i];
	for (int i=0,j=0;i<n;i++)
	{
		while (j<m && b[j]<a[i]-x) j++;
		if (j==m) break;
		if (b[j]>=a[i]-x && b[j]<=a[i]+y) rx[ans]=i, ry[ans++]=j++;
	}
	cout << ans << endl;
	rep(i,ans) cout << rx[i]+1 << ' ' << ry[i]+1 << endl;
}