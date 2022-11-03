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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9+1;
const int N = 1e6 + 10;

class Point
{
public:
	LL x, y;
	Point(){}
	Point(LL _x, LL _y) : x(_x), y(_y){}
	bool operator < (Point& p)
	{
		if (x != p.x) return x < p.x;
		else return y < p.y;
	}
};

vector<Point> vp;
vector<Point> v;

LL dist(Point p1, Point p2)
{
	LL dx = p1.x - p2.x;
	LL dy = p1.y - p2.y;
	return dx*dx + dy*dy;
}
LL dq(int l, int r)
{
	if (l >= r) return INF;
	LL mid = (l + r) >> 1;
	
	LL t1 = dq(l, mid);
	LL t2 = dq(mid + 1, r);
	LL d = min(t1, t2);
	v.clear();
	for (int i = l; i <= r; i++) if ((l+r-2LL*i)*(l+r-2LL*i) < 4*d) v.push_back({ vp[i].y, vp[i].x });
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 1; j < 8 && i+j < v.size(); j++)
		{
			d = min(d, dist(v[i], v[j+i]));
		}
	}
	return d;
	

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	LL sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		sum += x;
		vp.push_back({ i, sum });
	}
	cout << dq(0, n-1) << endl;

	return 0;
}