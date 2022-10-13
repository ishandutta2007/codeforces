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

int n,x[222],y[222],ans;

int isSuperCentral(int i)
{
	int res=0;
	rep(j,n)
	{
		if (x[i]==x[j] && y[j]<y[i]) res|=1;
		if (x[i]==x[j] && y[j]>y[i]) res|=2;
		if (y[i]==y[j] && x[j]<x[i]) res|=4;
		if (y[i]==y[j] && x[j]>x[i]) res|=8;
	}
	return res==15;
}

int main()
{
	cin >> n;
	rep(i,n) cin >> x[i] >> y[i];
	rep(i,n) ans+=isSuperCentral(i);
	cout << ans << endl;
}