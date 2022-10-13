#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define F first
#define S second
#define oo 1000111222
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

int m,n,a,b,nn;

int calc(int x,int y,int xx,int yy)
{
	if (x==xx) return 1;
	if (xx==n && yy==nn) yy=m-1;
	if (!y && yy==m-1) return 1;
	if (x+1==xx) return 2;
	if (!y || yy==m-1) return 2;
	if (yy+1==y) return 2;
	return 3;
}

int main()
{
	int x,y,xx,yy;
	cin >> n >> m >> a >> b;
	a--; b--; n--; nn=n%m; n/=m;
	x=a/m; y=a%m;
	xx=b/m; yy=b%m;
	cout << calc(x,y,xx,yy) << endl;	
	return 0;
}