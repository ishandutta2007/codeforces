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
	int hp,atk,def;
	int hp2,atk2,def2;
	int ch,ca,cd;
	cin >> hp >> atk >> def;
	cin >> hp2 >> atk2 >> def2;
	cin >> ch >> ca >> cd;
	int res = INF;
	
	for(int i=1;i<=100;i++)
	{
		int x = (hp2+i-1)/i;
		int ret = (max(x+def2,atk)-atk) * ca;
		
		for(int j=0;j<=200;j++)
		{
			int ret2 = cd*j;
			int s = (atk2 - def - j)*i;
			if(hp-s <= 0)
			{
				res = min(res,ret+ret2+ch*(1-hp+s));
			}
			else
			{
				res = min(res,ret+ret2);
			}
		}
	}
	cout << res << endl;
}