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
int main()
{
	srand((unsigned int)time(NULL));
	int n,m; scanf("%d %d",&n,&m);
	int ret;
	for(int i=1;i<=3000;i++)
	{
		if(i%2==1)
		{
			if(i*(i-1)/2+1<=n) ret=i;
		}
		else
		{
			if(i*(i-1)/2+i/2<=n) ret=i;
		}
	}
	ret=min(ret,m);
	vector<int>vec;
	for(int i=0;i<m;i++) {int x,y; scanf("%d %d",&x,&y); vec.pb(y);}
	sort(vec.begin(),vec.end(),greater<int>());
	ll ans=0LL;
	for(int i=0;i<ret;i++) ans+=vec[i];
	printf("%lld\n",ans);
	
}