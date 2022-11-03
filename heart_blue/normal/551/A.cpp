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
const LL INF = 1e9;
const int N = 2e5;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2)->
		bool{ return p1.first > p2.first; });
	vector<int> ans(n);
	ans[v[0].second] = 1;
	for (int i = 1; i < n; i++)
	{
		if (v[i].first == v[i - 1].first)
		{
			ans[v[i].second] = ans[v[i-1].second];
		}
		else ans[v[i].second] = i + 1;
	}
	for (auto &x : ans) cout << x << ' ';

	return 0;

}