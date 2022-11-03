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
const LL INF = 1e17;
const int N = 2e5+10;

vector<int> a[N];
list<int> ans;
vector<int> tmp;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int a[128] = { 0 };
	int n;
	string str;
	cin >> n >> str;
	n = str.length();
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i & 1)
		{
			if (a[str[i]]) a[str[i]]--;
			else ans++;
		}
		else
		{
			a[str[i] - 32]++;
		}
	}
	cout << ans << endl;
	return 0;
}