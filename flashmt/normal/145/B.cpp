#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdlib>
#define fr(a,b,c) for (int a=b;a<=c;a++)
#define frr(a,b,c) for (int a=b;a>=c;a--)
#define rep(a,b) for (int a=0;a<b;a++)
#define repp(a,b) for (int a=b-1;a>=0;a--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) int(a.size())
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define oo 1000111222
#define maxN 1
using namespace std;

int ans[1000100],a,b,c,d;

void quit()
{
	puts("-1");
	exit(0);
}

int main()
{
	cin >> a >> b >> c >> d;
	if (max(c,d)>min(a,b)) quit();
	if (abs(c-d)>1) quit();
	if (a+b<=c+d) quit();
	
	if (c>d)
	{
		rep(i,a-c) printf("4");
		rep(i,c) printf("47");
		rep(i,b-c) printf("7");
	}
	if (c<d)
	{
		printf("74");
		rep(i,a-d) printf("4");
		rep(i,d-2) printf("74");
		rep(i,b-d) printf("7");
		printf("74");
	}
	if (c==d)
	{
		if (a>c)
		{
			rep(i,a-c-1) printf("4");
			rep(i,c) printf("47");
			rep(i,b-c) printf("7");
			printf("4");
		}
		else
		{
			rep(i,c) printf("74");
			rep(i,b-c) printf("7");
		}
	}
	puts("");
	
}