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

int n,scoreX,scoreY;
pair <int,int> a[100100];
vector <int> X,Y;

int main()
{
	cin >> n;
	rep(i,n) scanf("%d",&a[i].fi), a[i].se=i+1;
	sort(a,a+n);
	for (int i=n-1;i>0;i-=2)
	{
		if (scoreX>=scoreY)
		{
			X.pb(a[i-1].se); scoreX+=a[i-1].fi;
			Y.pb(a[i].se); scoreY+=a[i].fi;
		}
		else
		{
			X.pb(a[i].se); scoreX+=a[i].fi;
			Y.pb(a[i-1].se); scoreY+=a[i-1].fi;
		}
	}
	if (n&1)
	{
		if (scoreX>=scoreY) Y.pb(a[0].se), scoreY+=a[0].fi;
		else X.pb(a[0].se), scoreX+=a[0].fi;
	}
	cout << sz(X) << endl;
	rep(i,sz(X)) printf("%d ",X[i]); puts("");
	cout << sz(Y) << endl;
	rep(i,sz(Y)) printf("%d ",Y[i]); puts("");
	//cout << scoreX << ' ' << scoreY << endl;
}