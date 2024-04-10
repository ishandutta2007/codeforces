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
int n;
int main()
{
	srand((unsigned int)time(NULL));
	map<int,int>ma;
	map<int,int>ma2;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		ma[x]++;
		if(x!=y) ma2[y]++;
	}
	int ret=INF;
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();++it)
	{
		int m=it->sc;
		int x=ma2[it->fi];
		if(m+x>=(n+1)/2) ret=min(ret,max(0,(n+1)/2-m));
	}
	for(map<int,int>::iterator it=ma2.begin();it!=ma2.end();++it)
	{
		int m=ma[it->fi];
		int x=it->sc;
		if(m+x>=(n+1)/2) ret=min(ret,max(0,(n+1)/2-m));
	}
	cout << (ret==INF?-1:ret) << endl;
}