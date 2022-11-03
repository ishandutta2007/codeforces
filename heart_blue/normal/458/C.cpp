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
const LL INF = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 1e4;

vector<int> v[N];

int check(int x, int _sum)
{
	int ans = 0;
	int sum = _sum;
	vector<int> vv;
	for (int i = 1; i < N; i++)
	{
		if (v[i].empty()) continue;
		int t = x;
		int n = v[i].size();
		for (int j = 0; j < x-1 && j < n; j++)
		{
			vv.push_back(v[i][j]);
		}
		for (int j = x-1; j < n; j++)
		{
			sum++;
			ans += v[i][j];
		}
	}
	if (sum >= x) return ans;
	sort(vv.begin(), vv.end());
	int k = 0;
	while (sum < x)
	{
		sum++;
		ans += vv[k++];
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 0) sum++;
		else v[x].push_back(y);
	}
	for (int i = 0; i < N; i++) if (!v[i].empty()) sort(v[i].rbegin(), v[i].rend());
	int l = sum;
	int r = n;
	int ans = -1;
	if (l == 0) l = 1;
	while (l < r)
	{
		int mid1 = (l + r) >> 1;
		int mid2 = ((mid1 + r) >> 1);
		if (mid1 == mid2) mid2++;
		if (mid2 > r) mid2 = r;
		int ans1 = check(mid1,sum);
		int ans2 = check(mid2,sum);
		if (ans1 > ans2) l = mid1 + 1, ans = ans2;
		else ans = ans1, r = mid2 - 1;
	}
	cout << check(l,sum) << endl;
	
	return 0;

}