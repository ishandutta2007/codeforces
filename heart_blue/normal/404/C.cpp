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
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
#define ABS(x) ((x) > 0 ? (x):(-x))
const int N = 100001;
vector<int> v[N];
class Edge
{
public:
	int u, v;
	Edge(){}
	Edge(int _u, int _v){ u = _u; v = _v; }
	bool operator <(const Edge &e)
	{
		if (u != e.u) return u < e.u;
		else return v < e.v;
	}
};
vector<Edge> ve;
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, k;
	cin >> n >> k;
	int maxv = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		maxv = max(x, maxv);
		v[x].push_back(i + 1);
	}
	if (v[0].size() != 1)
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = maxv; i >= 0; i--)
	{
		if (v[i].size() == 0)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < maxv; i++)
	{
		int t = 0;
		for (int s = 0; s < v[i].size(); s++)
		{
			int cnt = k;
			if (i) cnt--;
			for (; t < v[i + 1].size(); t++)
			{
				if (cnt == 0) break;
				ve.push_back(Edge(v[i][s], v[i + 1][t]));
				cnt--;
			}

		}
		if (t != v[i + 1].size())
		{
			cout << -1 << endl;
			return 0;
		}
	}
	for (int i = 0; i < ve.size(); i++)
	{
		if (ve[i].u > ve[i].v) swap(ve[i].u, ve[i].v);
	}
	sort(ve.begin(), ve.end());
	cout << ve.size() << endl;
	for (int i = 0; i < ve.size(); i++) cout << ve[i].u <<' ' << ve[i].v << endl;
	return 0;
}