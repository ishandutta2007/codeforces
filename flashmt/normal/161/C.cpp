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

int f(int a,int b,int c,int d,int k)
{
	if (a<=c && d<=b) return d-c+1;
	if (c<=a && b<=d) return b-a+1;
	
	if (k==1) return 1;
	
	int mid=1<<(k-1);
	if (a==mid) a++;
	if (b==mid) b--;
	if (c==mid) c++;
	if (d==mid) d--;
	
	if (a>b || c>d) return 0;
	vector < pii > X,Y;
	if (a<mid) X.pb(mp(a,min(b,mid-1)));
	if (mid<b) X.pb(mp(max(a-mid,1),b-mid));
	if (c<mid) Y.pb(mp(c,min(d,mid-1)));
	if (mid<d) Y.pb(mp(max(c-mid,1),d-mid));	
	
	int res=0;
	if (max(a,c)<=min(b,d)) res=min(b,d)-max(a,c)+1;
	rep(i,sz(X))
		rep(j,sz(Y))
			res=max(res,f(X[i].fi,X[i].se,Y[j].fi,Y[j].se,k-1));
	
	return res;
}

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << f(a,b,c,d,30) << endl;
}