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
#define INF 2000000000
#define f first
#define s second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
double rec(int x,int y)
{
	if(y==n*(n-1)/2) return 0.0;
	x--;
	y++;
	if(y==n*(n-1)/2) return 1.0;
	return rec(x-1,y+1)+4.0;
}
int main()
{
	srand((unsigned int)time(NULL));
	vector<int>vec; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		vec.pb(x);
	}
	int val=0,val2;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(vec[i]>vec[j]) val++;
			else val2++;
		}
	}
	printf("%.6f\n",rec(val,val2));
}