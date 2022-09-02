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
typedef long long intr;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000

intr gcd(intr a,intr b){
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	return gcd(b,a%b);
}
int main(){
	intr n,m,x,y,a,b;
	cin >> n >> m >> x >> y >> a >> b;
	intr p=gcd(a,b);
	a/=p;
	b/=p;
	intr A=n/a;
	intr B=m/b;
	intr C=min(A,B);
	intr LA=a*C;
	intr LB=b*C;
	vector<intr> xcan,ycan;
	if(x*2<LA)
	{
		xcan.pb(0);
	}
	else if((n-x)*2<LA)
	{
		xcan.pb(n-LA);
	}
	else
	{
		if(LA%2==0)
		{
			xcan.pb(x-LA/2);
		}
		else
		{
			xcan.pb(x-(LA+1)/2);
		}
	}

	if(y*2<LB)
	{
		ycan.pb(0);
	}
	else if((m-y)*2<LB)
	{
		ycan.pb(m-LB);
	}
	else
	{
		if(LB%2==0)
		{
			ycan.pb(y-LB/2);
		}
		else
		{
			ycan.pb(y-(LB+1)/2);
		}
	}
	printf("%lld %lld %lld %lld\n",xcan[0],ycan[0],xcan[0]+LA,ycan[0]+LB);
	cin >> n;
}