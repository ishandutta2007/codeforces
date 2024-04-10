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
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		long long n,_k,d1,d2;
		cin >> n >> _k >> d1 >> d2;
		for(int a=-1;a<=1;a+=2)
		{
			for(int b=-1;b<=1;b+=2)
			{
				long long k = _k;
				//x,x+a*d1,x+a*d1+b*d2
				//3*x + 2*a*d1 + b*d2 = k
				k -= (2LL*a*d1+1LL*b*d2);
				if(k%3 == 0 && n%3 == 0)
				{
					long long x = k/3;
					long long y = x+1LL*a*d1;
					long long z = y+1LL*b*d2;
					long long ax = n/3-x;
					long long ay = n/3-y;
					long long az = n/3-z;
					if(min(min(x,y),z) < 0 || min(min(ax,ay),az) < 0) continue;
					//if(max(ax,max(ay,az))*2 <= ax+ay+az)
					{
						puts("yes");
						goto nxt;
					}
				}
			}
		}
		puts("no"); nxt:;
	}
}