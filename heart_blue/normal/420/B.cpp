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
const int N = 1e5 + 10;
int a[N];
int b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	MEM(b, 0);
	MEM(a, 0);
	int n, m;
	cin >> n >> m;
	char c;
	int x;
	vector<int> v;
	int cnt = 0;
	map<int, int> mm;
	for (int i = 0; i < m; i++)
	{
		cin >> c >> x;
		if (c == '+') v.push_back(1);
		else v.push_back(0);
		v.push_back(x);
	}
	for (int i = 0; i < m * 2; i+=2)
	{
		int t = v[i];
		int y = v[i + 1];
		if (a[y] == 0 && t == 0) b[y] = 1,cnt++;
		a[y] = t;
	}
	MEM(a, 0);
	for (int i = 0; i < m * 2; i+=2)
	{
		int t = v[i];
		int y = v[i + 1];
		if (t == 0)
		{
			cnt--;
			if (cnt) a[y] = 1;
			else mm[y] = 1;
		}
		else
		{
			if (cnt) a[y] = 1;
			else mm[y] = 1;
			cnt++;
		}
		b[y] = t;
	}
	int ans = 0;
	if (mm.size() > 1)
	{
		for (auto it = mm.begin(); it != mm.end(); it++)
		{
			a[it->first] = 1;
		}
	}
	for (int i = 1; i <= n; i++) ans += 1 - a[i];
	cout << ans << endl;
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		
		if (!a[i])
		{
			if (k++) cout << ' ';
			cout << i;
		}
	}
	if (ans) cout << endl;
	return 0;
}