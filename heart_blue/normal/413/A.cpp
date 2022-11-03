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
#define MP(x,y) make_pair(x,y) 
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))
string str;

int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, minv, maxv;
	cin >> n >> m >> minv >> maxv;
	int flag = 0;
	int x;
	int t = m;
	while (t--)
	{
		cin >> x;
		if (minv > x) flag = -1;
		if (maxv < x) flag = -1;
		if (minv == x) flag |= 1;
		if (maxv == x) flag |= 2;
	}
	if (flag < 0) cout << "Incorrect" << endl;
	else if (flag == 3) cout << "Correct" << endl;
	else if (flag == 0)
	{
		if (n - m >= 2) cout << "Correct" << endl;
		else cout << "Incorrect" << endl;
	}
	else
	{
		if (n - m >= 1) cout << "Correct" << endl;
		else cout << "Incorrect" << endl;
	}
	return 0;
}