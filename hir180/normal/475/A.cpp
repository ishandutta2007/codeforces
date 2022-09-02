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
string st[6]=
{
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};
int main()
{
	int n; cin >> n;
	if(n >= 1) st[1][1] = 'O';
	if(n >= 2) st[2][1] = 'O';
	if(n >= 3) st[3][1] = 'O';
	if(n >= 4) st[4][1] = 'O';
	int curx = 1,cury = 3;
	for(int i=5;i<=n;i++)
	{
		st[curx][cury] = 'O';
		if(curx == 4)
		{
			curx = 1; cury += 2;
		}
		else
		{
			if(curx == 1) curx++; else curx+=2;
		}
	}
	for(int i=0;i<6;i++) cout << st[i] << endl;
}