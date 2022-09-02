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
int n,m;
double c[100005];
vector<pair<int,double> > edge[100005];
int main()
{
	scanf("%d %d",&n,&m);
	if(m == 0)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&c[i]);
	}
	double res = 0;
	for(int i=0;i<m;i++)
	{
		int a,b;
		double cc;
		scanf("%d %d %lf",&a,&b,&cc);
		res = max(res,(c[a]+c[b])/cc);
	}
	printf("%.15f\n",res);
}