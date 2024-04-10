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
#define eps 1e-8
using namespace std;

double vp,vd,t,f,c;

int largerOrEqual(double x,double y)
{
	return x>y || fabs(x-y)<eps;
}

int canEscape(int num)
{
	if (largerOrEqual(vp,vd)) return 1;
	double traveled=t*vp;
	while (num>=0)
	{
		double need=traveled/(vd-vp);
		traveled+=need*vp;
		if (largerOrEqual(traveled,c)) break;
		num--;
		need=traveled/vd+f;
		traveled+=need*vp;
	}
	return num>=0;
}

int main()
{
	int low=0,high=1000000,ans=high;
	cin >> vp >> vd >> t >> f >> c;
	while (low<=high)
	{
		int mid=(low+high)>>1;
		if (canEscape(mid)) ans=mid, high=mid-1;
		else low=mid+1;
	}
	cout << ans << endl;
}