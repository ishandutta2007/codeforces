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
const double eps = 1e-10;
const LL N = 1e3 + 20;
int solve(string &str, int k)
{
	int n = str.length();
	int r = 0;
	int t = 0;
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		while (r < n)
		{
			if (str[r] == 'b')
			{
				if (t == k)
				{
					break;
				}
				else
				{
					sum++; 
					ans = max(sum, ans);
					t++;
					r++;
				}
			}
			else
			{
				r++;
				sum++;
				ans = max(sum, ans);
			}
		}
		if (r == n) break;
		if (str[i] == 'b') t--;
		sum--;
	}
	return ans;

}
int main()
{
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	
	string str;
	int n, k;
	cin >> n >> k;
	cin >> str;
	int ans1 = solve(str, k);
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a') str[i] = 'b';
		else str[i] = 'a';
	}
	int ans2 = solve(str, k);
	cout << max(ans1, ans2) << endl;
	
	return 0;
}