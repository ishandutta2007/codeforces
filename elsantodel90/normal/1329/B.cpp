#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>
#include <iomanip>



using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

typedef long long tint;

#define all(c) (c).begin(), (c).end()
#define esta(x,c) ((c).find(x) != (c).end())

tint MOD;

tint msb(tint x)
{
	assert(x >= 1);
	tint ret = 1;
	while (2*ret <= x)
		ret *= 2;
	return ret;
}

tint f(tint x)
{
	if (x == 0)
		return 0;
	if (x == 1)
		return 1%MOD;
	tint half = msb(x);
	tint fhalf = f(half-1);
	tint extra = (MOD+x- half+1)%MOD;
	return (fhalf + (extra * (1+fhalf))%MOD)%MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int TT; cin >> TT;
	forn(tt,TT)
	{
		tint d;
		cin >> d >> MOD;
		cout << f(d) << "\n";
	}	
	return 0;
}