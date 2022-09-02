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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
map<int,int>ma;
map<int,int>ma2;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y; scanf("%d %d",&x,&y);
		if(ma.find(x) == ma.end()) ma[x] = y;
		else ma[x] = min(ma[x],y);
		if(ma2.find(x) == ma2.end()) ma2[x] = y;
		else ma2[x] = max(ma2[x],y);
	}
	int t = 0;
	for(map<int,int>::iterator it = ma.begin();it != ma.end();++it)
	{
		if(it->sc >= t)
		{
			t = ma2[it->fi];
		}
		else
		{
			t = it->fi;
		}
	}
	printf("%d\n",t);
}