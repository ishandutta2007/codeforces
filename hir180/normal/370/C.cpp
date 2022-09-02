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
int n,m;
vector<int>vec;
int main()
{
	srand((unsigned int)time(NULL));
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x; scanf("%d",&x);
		vec.pb(x);
	}
	sort(vec.begin(),vec.end());
	int ret=0;
	for(int i=0;i<n;i++) ret+=(vec[i]!=vec[(i+n/2)%n]);
	printf("%d\n",ret);
	for(int i=0;i<n;i++) printf("%d %d\n",vec[i],vec[(i+n/2)%n]);
}