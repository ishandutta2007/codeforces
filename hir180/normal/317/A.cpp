#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
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
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define size (1<<21)
#define mod 1000000007

int main()
{
	long long x,y,m;
	cin >> x >> y >> m;
	if(max(x,y)>=m)
	{
		puts("0");
		return 0;
	}
	if(x>y) swap(x,y);
	if(y<=0) {puts("-1"); return 0;}
	long long ans=0;
	if(x<0)
	{
		ans+=(abs(x)/y);
		x+=(abs(x)/y)*y;
	}
	while(y<m)
	{
		x=x+y;
		if(x>y) swap(x,y);
		ans++;
	}
	cout << ans << endl;
}