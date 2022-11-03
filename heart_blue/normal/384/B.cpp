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
int ans[1001][1001];
vector<int> v1;
template <class T> void quicksort1(vector<T> &S, int a, int b) // EE
{
	int x = a;
	int y = b;
	T mid = S[(a + b) >> 1];
	while (x <= y)
	{
		while (S[x] < mid) x++;
		while (mid < S[y]) y--;
		if (x <= y)
		{
			swap(S[x], S[y]);
			if (x != y)
			{
				v1.push_back(x);
				v1.push_back(y);
			}
			ans[x][y] = 1;
			x++;
			y--;
		}
	}
	if (x < b) quicksort1(S, x, b);
	if (y > a) quicksort1(S, a, y);
}

template <class T> void quicksort2(vector<T> &S, int a, int b) // EE
{
	int x = a;
	int y = b;
	T mid = S[(a + b) >> 1];
	while (x <= y)
	{
		while (S[x] > mid) x++;
		while (mid > S[y]) y--;
		if (x <= y)
		{
			swap(S[x], S[y]);
			if (x != y)
			{
				v1.push_back(x);
				v1.push_back(y);
			}
			ans[x][y] = 1;
			x++;
			y--;
		}
	}
	if (x < b) quicksort2(S, x, b);
	if (y > a) quicksort2(S, a, y);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cin >> v[j];
		for (int j = 0; j < v1.size(); j+=2)
		{
			int x = v1[j];
			int y = v1[j + 1];
			if (k == 0 && v[x] > v[y]) swap(v[x], v[y]);
			if (k == 1 && v[x] < v[y]) swap(v[x], v[y]);
		}
		if (k == 0) quicksort1(v, 0, m - 1);
		else quicksort2(v, 0, m - 1);
	}
	int cnt = 0;
	
	cout << v1.size()/2 << endl;
	for (int i = 0; i < v1.size(); i += 2)
	{
		if (k == 0)
			cout << v1[i] + 1 << ' ' << v1[i + 1] + 1 << endl;
		else
			cout << v1[i + 1] + 1 << ' ' << v1[i] + 1 << endl;
	}
	

	return 0;
}