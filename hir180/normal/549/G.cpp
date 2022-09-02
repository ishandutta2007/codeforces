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
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int x[200005];
P y[200005];
int main()
{
	int n;
	
	cin >> n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x[i]);
		y[i] = P(x[i]+i,i);
	}
	sort(y,y+n);
	vector<int>res;
	for(int i=0;i<n;i++)
	{
		int val = y[i].fi-i;
		res.pb(val);
	}
	for(int i=1;i<n;i++) if(res[i-1]>res[i])
	{
		cout << ":(" << endl; return 0;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d%c",res[i],i==n-1?'\n':' ');
	}
}