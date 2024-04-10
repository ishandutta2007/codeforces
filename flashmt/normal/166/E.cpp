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
#define base 1000000007
using namespace std;

int f[2][4];

int main()
{
	int n,z;
	cin >> n;
	f[z=0][0]=1;
	while (n--)
	{
		z^=1;
		rep(i,4)
		{
			f[z][i]=0;
			rep(j,4) f[z][i]+=(i!=j)*f[1-z][j], f[z][i]%=base;
		}
	}
	cout << f[z][0] << endl;
}