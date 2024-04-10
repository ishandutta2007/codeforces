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


int main()
{
	//freopen("input.txt", "r", stdin);
	string str = "AHIMOTUVWXY";
	string s;
	map<char, int> mc;
	for (int i = 0; i < str.length(); i++) mc[str[i]] = 1;
	cin >> s;
	int l = s.length();
	int flag = 1;
	for (int i = 0; i < l; i++)
	{
		if (!mc.count(s[i])) flag = 0;
		if (s[i] != s[l - i - 1]) flag = 0;
	}
	if (flag) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}