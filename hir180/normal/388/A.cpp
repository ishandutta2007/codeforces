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
int num[105];
int n;
bool ok(int x)
{
	priority_queue<int>que;
	for(int i=0;i<x;i++)
	{
		if(num[i]) que.push(num[i]);
	}
	for(int i=x;i<n;i++)
	{
		if(que.empty()) return false;

			int a=que.top();  que.pop();
			a=min(a-1,num[i]);
			if(a) que.push(a);
	}
	return true;
}
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n,greater<int>());
	//(lb,ub]
	int lb=0,ub=n+5;
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(ok(mid)) ub=mid;
		else lb=mid;
	}
	printf("%d\n",ub);
}