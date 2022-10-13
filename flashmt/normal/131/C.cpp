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
#define maxN 1
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
#define oo 1000111222
using namespace std;

int n,m,t;
unsigned long long c[66][66],ans;

int main()
{
	fr(i,0,30) fr(j,0,i) c[i][j]=(j?c[i-1][j]+c[i-1][j-1]:1);
	cin >> n >> m >> t;
	fr(i,4,n)
		if (i<t)
			ans+=c[n][i]*c[m][t-i];
	cout << ans << endl;
}