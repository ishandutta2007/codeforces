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
	int x; cin >> x;

if(x==3){ cout << 5 << endl; return 0;}
	int even,odd;
	if(x%4!=0)
	{
		even=INF;
		goto nxt;
	}
	for(int i=2;;i+=2)
	{
		int sz=i/2-1;
		int lb=0;
		int ub=(sz*sz+1)/2;
		if(lb*4<=x && x<=ub*4)
		{
			even=i; break;
		}
	}
	nxt:;
	for(int i=1;;i+=2)
	{
		if(((i*i+1)/2)>=x)
		{
			odd=i; break;
		}
	}
	cout << (min(even,odd)) << endl;
}