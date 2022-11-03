#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e1 + 10;
int dx[] = { 1,1,1,-1,-1,-1,0,0 };
int dy[] = { -1,1,0,-1,1,0,-1,1 };
int flag[N][N];
pair<int, int> check(string& s)
{
	return { s[0] - 'a' + 1,s[1] - '0' };
}
void check(string& s1, string& s2, string& s3, string& s4)
{
	vector<string> v, vs;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	v.push_back(s4);
	vs.push_back(s1);
	vs.push_back(s2);
	int x, y;
	tie(x, y) = check(s4);
	MEM(flag, 0);
	for (auto& p : v)
	{
		int a, b;
		tie(a, b) = check(p);
		flag[a][b] = 1;
	}
	for (auto& s : vs)
	{
		int a, b;
		tie(a, b) = check(s);
		if (a == x || b == y)
		{
			int ox = x - a;
			int oy = y - b;
			if (ox > 0) ox = 1;
			if (ox < 0) ox = -1;
			if (oy > 0) oy = 1;
			if (oy < 0) oy = -1;
			while (1)
			{
				a += ox;
				b += oy;
				if (a == x && b == y)
				{
					return;
				}
				if (a < 1 || a > 8) break;
				if (b < 1 || b > 8) break;
				if (flag[a][b]) break;
			}
		}
	}
	puts("OTHER");
	exit(0);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	check(s1, s2, s3, s4);
	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);
	int kx, ky;
	tie(kx, ky) = check(s3);
	for (int o = 0; o < 8; o++)
	{
		int x, y;
		tie(x, y) = check(s4);
		x += dx[o];
		y += dy[o];
		if (x < 1 || x > 8) continue;
		if (y < 1 || y > 8) continue;
		//if (kx == x && ky == y) puts("OTHER"),exit(0);
		MEM(flag, 0);
		flag[x][y] = 1;
		vector<string> vs;
		vs.push_back(s1);
		vs.push_back(s2);
		int ok = 0;
		for (auto& s : v)
		{
			int x, y;
			tie(x, y) = check(s);
			flag[x][y] = 1;
		}
		for (auto& s : vs)
		{
			int a, b;
			tie(a, b) = check(s);
			if (a == x && b == y) continue;
			if (a == x || b == y)
			{
				int ox = x - a;
				int oy = y - b;
				if (ox > 0) ox = 1;
				if (ox < 0) ox = -1;
				if (oy > 0) oy = 1;
				if (oy < 0) oy = -1;
				while (1)
				{
					a += ox;
					b += oy;
					if (a == x && b == y)
					{
						ok = 1;
						break;
					}
					if (a < 1 || a > 8) break;
					if (b < 1 || b > 8) break;
					if (flag[a][b]) break;
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			int a, b;
			tie(a, b) = check(s3);
			a += dx[i];
			b += dy[i];
			if (a == x && b == y)
				ok = 1;
		}
		if (ok == 0)
			puts("OTHER"), exit(0);
	}
	puts("CHECKMATE");
	return 0;
}