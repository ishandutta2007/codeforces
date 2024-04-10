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

int main()
{
	int x,y,z,x1,y1,z1,a[6],ans=0;
	cin >> x >> y >> z >> x1 >> y1 >> z1;
	rep(i,6) cin >> a[i];
	
	if (y<0) ans+=a[0];
	if (y>y1) ans+=a[1];
	if (z<0) ans+=a[2];
	if (z>z1) ans+=a[3];
	if (x<0) ans+=a[4];
	if (x>x1) ans+=a[5];
	
	cout << ans << endl;
}