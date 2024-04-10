//Daily Lunch Special Tanoshii !!
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define s(x) scanf("%d",&x)
#define rep(i,x) for(int i=0;i<x;i++)
P v[300005];
int ret[300005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int vl; scanf("%d",&vl);
		v[i]=mp(vl,i);
	}
	sort(v,v+n);
	int prev=-1;
	for(int i=0;i<n;i++)
	{
		if(prev>=v[i].first)
		{
			prev++;
			ret[v[i].second]=prev;
		}
		else
		{
			prev=v[i].first;
			ret[v[i].second]=prev;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d%c",ret[i],i==n-1?'\n':' ');

	}
}