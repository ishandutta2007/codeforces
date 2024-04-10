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

int solve(int a,int x,int y)
{
	if (y%a==0) return -1;
	int row=y/a+1;
	if (row==1 || row%2==0) 
	{
		if (x*2<=-a || x*2>=a) return -1;
		return (row==1?1:row/2*3-1);
	}
	if (x<=-a || x>=a || !x) return -1;
	return row/2*3+(x>0);
}

int main()
{
	int a,x,y;
	cin >> a >> x >> y;
	cout << solve(a,x,y) << endl;
}