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
	if(n == 0)
	{
		printf("0 %d\n",1);
		printf("0 %d\n",m);
		printf("0 0\n");
		printf("0 %d\n",m-1);
		return 0;
	}
	else if(m == 0)
	{
		printf("%d 0\n",1);
		printf("%d 0\n",n);
		printf("0 0\n");
		printf("%d 0\n",n-1);
		return 0;
	}
	if(n < m)
	{
		long long a = 1LL*(n-1)*(n-1)+1LL*m*m+1LL*n*n+1LL*m*m+1LL*(n-1)*(n-1)+1LL*m*m;
		long long b = 1LL*n*n+1LL*m*m+1LL*m*m+1LL*m*m+1LL*n*n;
		if(a>=b)
		{	printf("1 0\n");
			printf("%d %d\n",n,m);
			printf("0 0\n");
			printf("%d %d\n",n-1,m);
		}
		else
		{
			printf("0 0\n");
			printf("%d %d\n",n,m);
			printf("%d 0\n",n);
			printf("%d %d\n",0,m);
		}
	}
	else
	{
		long long a = 1LL*n*n+1LL*(m-1)*(m-1)+1LL*n*n+1LL*m*m+1LL*n*n+1LL*(m-1)*(m-1);
		long long b = 1LL*n*n+1LL*m*m+1LL*n*n+1LL*m*m+1LL*n*n;
		if(a>=b)
		{
			printf("0 1\n");
			printf("%d %d\n",n,m);
			printf("0 0\n");
			printf("%d %d\n",n,m-1);
		}
		else
		{
			printf("0 0\n");
			printf("%d %d\n",n,m);
			printf("0 %d\n",m);
			printf("%d %d\n",n,0);
		}
	}
	
}