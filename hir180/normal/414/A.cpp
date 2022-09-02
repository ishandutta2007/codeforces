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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)

int main()
{
	int n,m;
	cin >> n >> m;
	if(n==1)
	{
		if(!m) puts("1");
		else puts("-1");
		return 0;
	}
	if(m < n/2)
	{
		puts("-1");
		return 0;
	}
	int v = m - (n/2-1);
	vector<int>res;
	res.pb(v); res.pb(v*2);
	for(int i=5*1e8;res.size()<n;i++)
	{
		res.pb(i);
	}
	for(int i=0;i<n;i++) printf("%d ",res[i]);
	puts("");
}