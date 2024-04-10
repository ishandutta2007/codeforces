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
ll cnt[1000005];
int main()
{
	ll n,m; scanf("%lld %lld",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v; scanf("%d %d",&u,&v);
		cnt[u]++; cnt[v]++;
	}
	ll ret=1LL*m*(n-2LL);
	for(int i=1;i<=n;i++) ret-=cnt[i]*(cnt[i]-1LL)/2LL;
	cout << 1LL*n*(n-1LL)*(n-2LL)/6LL-ret << endl;
}