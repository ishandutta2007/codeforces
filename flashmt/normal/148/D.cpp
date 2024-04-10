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

int w,b;
double prob[2][1010][1010];

double win(int w,int b,int dragonTurn)
{
	if (!w) return 1.0*dragonTurn;
	if (!b) return 1.0;
	if (prob[dragonTurn][w][b]>-0.5) return prob[dragonTurn][w][b];
	double res=1.0*w/(w+b);
	if (dragonTurn)
	{
		res+=(1.0-win(w-1,b-1,0))*w/(w+b-1)*b/(w+b);
		if (b>1) res+=(1.0-win(w,b-2,0))*(b-1)/(w+b-1)*b/(w+b);
	}
	else res+=(1.0-win(w,b-1,1))*b/(w+b);
	return prob[dragonTurn][w][b]=res;
}

int main()
{
	memset(prob,-1,sizeof(prob));
	cin >> w >> b;
	printf("%.9lf\n",win(w,b,0));
}