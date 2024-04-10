#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
typedef pair<double,double> Q;
double det(Q a,Q b)
{
	return a.fi*b.sc - a.sc*b.fi;
}
double a,b,c,d;
int n;
int main()
{
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	scanf("%d",&n);
	int res = 0;
	for(int i=0;i<n;i++)
	{
		double x,y,z;
		scanf("%lf%lf%lf",&x,&y,&z);
		bool s=0,t=0;
		s = (x*a+y*b+z < 0);
		t = (x*c+y*d+z < 0);
		res += (s^t);
	}
	cout << res << endl;
}