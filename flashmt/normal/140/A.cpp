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

int n,r,R;

int main()
{
	cin >> n >> R >> r;
	if (r>R)
	{
		puts("NO");
		return 0;
	}
	if (n==1)
	{
		puts("YES");
		return 0;
	}
	if (r==R)
	{
		puts("NO");
		return 0;
	}	
	int t=R-r;
	double x=1.0-2.0*r*r/t/t;
	x=acos(x);
	puts(x*n-2.0*acos(-1.0)<1e-8?"YES":"NO");
}