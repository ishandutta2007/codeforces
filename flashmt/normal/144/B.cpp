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

int a[1010][1010],xa,xb,ya,yb,n,x[1010],y[1010],r[1010],ans;

int out(int X,int Y)
{
	rep(i,n) 
		if ((X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i])<=r[i]*r[i]) return 0;
	return 1;
}

int main()
{
	cin >> xa >> ya >> xb >> yb >> n;
	if (xa>xb) swap(xa,xb);
	if (ya>yb) swap(ya,yb);
	rep(i,n) cin >> x[i] >> y[i] >> r[i];
	fr(i,ya,yb) ans+=out(xa,i)+out(xb,i);
	fr(i,xa+1,xb-1) ans+=out(i,ya)+out(i,yb);
	cout << ans << endl;
}