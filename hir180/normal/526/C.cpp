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
ll c,hr,hb,wr,wb;
void solvebyred()
{
	ll ret = 0;
	for(ll i=0;i*wr<=c;i++)
	{
		ll zan = c-i*wr;
		zan /= wb;
		ret = max(ret,i*hr+zan*hb);
	}
	cout << ret << endl;
}
void solvebyblue()
{
	ll ret = 0;
	for(ll i=0;i*wb<=c;i++)
	{
		ll zan = c-i*wb;
		zan /= wr;
		ret = max(ret,i*hb+zan*hr);
	}
	cout << ret << endl;
}
void solvebydp()
{
	ll dp[350*350]={};
	dp[0] = 0;
	for(int i=0;i<350*350;i++)
	{
		if(i+wr<350*350) dp[i+wr] = max(dp[i+wr],dp[i]+hr);
		if(i+wb<350*350) dp[i+wb] = max(dp[i+wb],dp[i]+hb);
	}
	ll ret = 0;
	for(ll i=0;i<=min(c,wr*wb);i++)
	{
		ll x = dp[i]+max(((c-i)/wr)*hr,((c-i)/wb)*hb);
		ret = max(ret,x);
	}
	cout << ret << endl;
}
int main()
{
	cin >> c >> hr >> hb >> wr >> wb;
	if(wr >= 334) solvebyred();
	else if(wb >= 334) solvebyblue();
	else solvebydp();
}