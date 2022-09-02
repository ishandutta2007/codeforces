//E? Nanndatte?
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
	int x,y;
	cin >> x >> y;
	if(x>=0 && y>=0)
	{
		printf("%d %d %d %d\n",0,x+y,x+y,0 );
	}
	if(x>=0 && y<0)
	{
		printf("%d %d %d %d\n",0,y-x,x-y,0 );
	}

	if(x<0 && y<0)
	{
		printf("%d %d %d %d\n",x+y,0,0,x+y );
	}

	if(x<0 && y>=0)
	{
		printf("%d %d %d %d\n",x-y,0,0,y-x );
	}
}