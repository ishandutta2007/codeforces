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

int main()
{
	//freopen("input.txt", "r", stdin);
	vector<int> v;
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	int maxv = 0;
	for (int i = 1; i < n; i++)
	{
		maxv = max(maxv,v[i-1] - v[i]);
	}
	cout << max(maxv - m, 0) << endl;
	return 0;
}