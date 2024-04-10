//Bokann ga bokka--nn!!
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
int main(){
	int r1,c1,r2,c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int a,b,c;
	if(r1==r2 && c1==c2) a=0;
	else if(r1==r2 || c1==c2) a=1;
	else a=2;

	if(abs(r1+c1-r2-c2)%2!=0)
	{
		b=0;
	}
	else
	{
		if(r1-c1==r2-c2 || r1+c1==r2+c2) b=1;
		else b=2;
	}

	c=max(abs(r1-r2),abs(c1-c2));

	printf("%d %d %d\n",a,b,c);
}