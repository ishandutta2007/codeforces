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

int a[333];

int solve(int n,int d,int m)
{
	if (n==1)
	{
		if (d<1 || d>m) return 0;
		a[n]=d;
		return 1;
	}
	
	int L=(n+1)/2,R=n-L;
	if (L-m*R>d || L*m-R<d) return 0;
	fr(i,1,m)
		if (solve(n-1,i-d,m))
		{
			a[n]=i;
			return 1;
		}
	return 0;
}

int main()
{
	int n,d,m;
	cin >> n >> d >> m;
	if (!solve(n,d,m)) puts("-1");
	else
		frr(i,n,1) cout << a[i] << (i==1?'\n':' ');
}