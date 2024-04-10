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
int num[55];
vector<int>vec;
bool dp[500005];
int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num,num+n);
	dp[0]=true;
	for(int i=0;i<n;i++)
	{
		for(int j=500000;j>=num[i];j--)
		{
			if(dp[j-num[i]]) dp[j]=true;
		}
	}
	for(int i=0;i<=500000;i++) if(dp[i]) vec.pb(i);
	int ret=0; int cur=0;
	while(1)
	{
		int s=upper_bound(vec.begin(),vec.end(),cur+m)-vec.begin(); s--;
		if(cur==vec[s]) break;
		ret++;
		cur=vec[s];
	}
	printf("%d %d\n",cur,ret);
}