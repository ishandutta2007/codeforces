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
int a[128][128];
int main()
{
	//freopen("input.txt", "r", stdin);
	string str1, str2;
	for (int i = 0; i < 128; i++) a[i][i] = 0;

	a['8']['['] = 1;
	a['[']['('] = 1;
	a['(']['8'] = 1;
	a['[']['8'] = -1;
	a['(']['['] = -1;
	a['8']['('] = -1;
	int ans = 0;
	cin >> str1 >> str2;
	for (int i =0; i < str1.length(); i += 2)
	{
		ans += a[str1[i]][str2[i]];
	}
	if (ans > 0) cout << "TEAM 1 WINS" << endl;
	else if (ans < 0) cout << "TEAM 2 WINS" << endl;
	else cout << "TIE" << endl;
	return 0;
}