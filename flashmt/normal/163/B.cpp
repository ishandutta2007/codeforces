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

int n,k,h,which[100100];
pair <pair<int,int>,int> a[100100];

int possible(double t,int k)
{
	int kk=1;
	rep(i,n)
		if (t>=1.0*kk*h/a[i].fi.se)
		{
			which[kk++]=a[i].se;
			if (k<kk) return 1;
		}
	return 0;
}

int main()
{
	cin >> n >> k >> h;
	rep(i,n) cin >> a[i].fi.fi;
	rep(i,n) cin >> a[i].fi.se;
	rep(i,n) a[i].se=i+1;
	sort(a,a+n);
	
	double low=0,high=1e9,ans=0;
	rep(i,200)
	{
		double mid=(low+high)/2;
		if (possible(mid,k)) ans=mid, high=mid;
		else low=mid;
	}
	possible(ans,k);
	fr(i,1,k) cout << which[i] << ' ';
}