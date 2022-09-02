//IOI2014
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
bool win[1005][1005]={};
int main()
{
	srand((unsigned int)time(NULL));
	int n,k;
	cin >> n >> k;
	if(n*k > n*(n-1)/2)
	{
		cout << -1 << endl;
		return 0;
	}
	printf("%d\n",n*k);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=i+k;j++)
		{
			int x=j;
			if(j > n) x-=n;
			printf("%d %d\n",i,x);
		}
	}
}