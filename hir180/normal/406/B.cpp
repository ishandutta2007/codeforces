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
bool used[1000005];
int main()
{
	srand((unsigned int)time(NULL));
	int n;
	scanf("%d",&n);
	vector<int>vec,res;
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		vec.pb(x); used[x]=true;
	}
	int tot=0;
	for(int i=1;i<=500000;i++)
	{
		if(used[i] && used[1000001-i]) tot++;
	}
	printf("%d\n",n);
	for(int i=1;i<=500000;i++)
	{
		if(!used[i] && !used[1000001-i] && tot)
		{
			tot--;
			printf("%d %d ",i,1000001-i);
		}
		else if(!used[i] && used[1000001-i])
		{
			printf("%d ",i);
		}
		else if(!used[1000001-i] && used[i])
		{
			printf("%d ",1000001-i);
		}
	}
}