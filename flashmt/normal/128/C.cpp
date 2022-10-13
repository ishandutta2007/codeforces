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
#define oo 1000111222
#define z 1000000007
using namespace std;

int n,m,k,c[2010][2010];

int main()
{
	cin >> m >> n >> k;
	fr(i,0,2000) fr(j,0,i) c[i][j]=(j && j<i?(c[i-1][j]+c[i-1][j-1])%z:1);
	long long ans=1LL*c[n-1][k*2]*c[m-1][k*2]%z;
	cout << ans << endl;
}