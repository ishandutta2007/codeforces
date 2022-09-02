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
int main()
{
	int n,m;
	cin >> n >> m;
	if(n == 1){puts("1.0"); return 0;}
	if(m == 1){printf("%.12f\n",1.0/n); return 0;}
	double res = 0.0;
	double cur = 1.0;
	for(int i=m*n-m;i>=m*n-m-n+1;i--) cur *= (double)i/(double)(i+m-1);
	cur*=(double)(m-1);
	double a = 1.0;
	for(int i=0;i<=min(n-1,m-1);i++)
	{
		//mn-m C n-1-i / mn-1 C n * i+1 / n 
		cur *= (double)(n-i)/(double)(m*n-m-n+i+1);
		res += cur * (double)(i+1)/ (double)n*a;
		a*=(double)(m-i-1)/(double)(i+1);
	}
	printf("%.12f\n",res);
}