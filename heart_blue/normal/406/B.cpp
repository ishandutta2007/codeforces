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
const int N = 1e6+1;
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	int s = N;
	MEM(a, 0);
	int n;
	int x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		a[x] = 1;
	}
	int l = 1;
	vector<int> ans;
	for (int i = 1; i < N; i++)
	{
		if (a[i] == 1)
		{
			if (a[s - i] == 0) ans.push_back(s - i);
			else
			{
				while (true)
				{
					if (a[l] == 0 && a[s - l] == 0)
					{
						ans.push_back(l);
						ans.push_back(s - l);
						a[l] = a[s - l] = -1;
						break;
					}
					else l++;
				}
			}
			a[s - i] = a[i] = -1;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
	return 0;
}