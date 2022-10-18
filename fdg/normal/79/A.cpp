#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <cstdio>
#include <ctime>

#define ll long long

using namespace std;

pair <int,int> F(int x,int y)
{
	if (x>=2&&y>=2) return make_pair(2,2);
	if (x>=1&&y>=12) return make_pair(1,12);
	if (y>=22) return make_pair(0,22);
	return make_pair(-1,-1);
}

pair <int,int> S(int x,int y)
{
	if (y>=22) return make_pair(0,22);
	if (x>=1&&y>=12) return make_pair(1,12);
	if (x>=2&&y>=2) return make_pair(2,2);
	return make_pair(-1,-1);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int x,y,cnt=0;
	cin >> x >> y;
	while(true)
	{
		pair <int,int> f;
		if (cnt&1) f=S(x,y);
		else f=F(x,y);
		if (f.first==-1) break;
		x-=f.first; y-=f.second;
		cnt++;
	}
	if (cnt&1) cout << "Ciel\n";
	else cout << "Hanako\n";
	return 0;
}