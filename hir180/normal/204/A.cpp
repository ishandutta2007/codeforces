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
	ll lb,ub,sum=0LL;
	cin >> lb >> ub;
	ll t[19];
	t[0]=1LL;
	for(int i=1;i<=18;i++) t[i]=t[i-1]*10LL;
	for(int i=1;i<=9;i++) if(lb<=i && i<=ub) sum++;
	for(int i=2;i<=18;i++)
	{
		for(int j=1;j<=9;j++)
		{
			//j....j
			long long val=0;
			val+=1LL*j; val+=1LL*t[i-1]*j;
			ll rem=lb-val;
			ll rem2=ub-val;
			if(rem2<0) continue;
			ll minv=0LL;
			ll maxv=t[i-2]-1LL;
			rem=max(0LL,(rem+9)/10LL); minv=max(minv,rem);
			rem2/=10LL; maxv=min(maxv,rem2);
			if(minv<=maxv) sum+=(maxv-minv+1);
		}
	}
	cout << sum << endl;
}