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
	int z,o;
	cin >> z >> o;
	if(z>o+1 || 2*z+2<o)
	{
		puts("-1");
		return 0;
	}
	if(z==o+1)
	{
		for(int i=0;i<z+o;i++)
		{
			cout << i%2;
		}
		cout << endl;
		return 0;
	}
	if(o>2*z)
	{
		for(int i=0;i<z+o;i++)
		{
			if(i%3==2) cout << 0;
			else cout << 1 ;
		}
		cout << endl;
		return 0;
	}
	int rem=o-z;
	int ord=z-rem;
	while(rem--) cout << "110";
	while(ord--) cout << "10";
	cout << endl;
}