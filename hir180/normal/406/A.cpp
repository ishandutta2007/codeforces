//Bokan ga bokka--nn!!
//Daily Lunch Special Tanoshii !!
//HIR180
//IOI2014N
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
	srand((unsigned int)time(NULL));
	int n;
	int c[1005][1005];
	cin >> n;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&c[i][j]);
			if(i==j) tot+=c[i][j];
		}
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++)
	{
		int t; scanf("%d",&t);
		if(t==3)
		{
			cout << (tot%2);
		}
		else
		{
			int x; scanf("%d",&x);
			c[x][x] = 1-c[x][x];
			tot += c[x][x]?1:-1;
		}
	}
	puts("");
}