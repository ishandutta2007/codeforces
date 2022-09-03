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
bool ok[1005];
P make[1005];
int main()
{
	srand((unsigned int)time(NULL));
	int a,b;
	cin >> a >> b;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(i*i+j*j == a*a)
			{
				if((b*i) % a == 0 && (b*j) % a == 0)
				{
					int ax=i,ay=j;
					int bx=(b*i)/a,by=(b*j)/a;
					if(ax==by && ay==bx) continue;
					puts("YES");
					puts("0 0");
					if(ax!=by)
					{
						cout << -ay << " " << ax << endl;
						cout << bx << " " << by << endl;
					}
					else if(ay!=bx)
					{
						cout << -ax << " " << ay << endl;
						cout << by << " " << bx << endl;
					}
					return 0;
				}
			}
		}
	}
	puts("NO");
}