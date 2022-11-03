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
LL getans(int x)
{
	int l = x - 1;
	LL cnt1 = 0;
	while (l >= 0)
	{
		if (isalpha(str[l])) cnt1++;
		if (str[l] == '@' || str[l] == '.') break;
		l--;
	}
	int flag1 = 0;
	int flag2 = 0;
	LL cnt2 = 0;
	int r = x + 1;
	while (r < str.length())
	{
		if (str[r] == '@' || str[r] == '_') break;
		if (isalnum(str[r]))
		{
			flag1 = 1;
			if (flag2)
			{
				if (isdigit(str[r])) break;
				else cnt2++;
			}
		}
		if (str[r] == '.')
		{
			if (flag2 || !flag1) break;
			flag2 = 1;
		}
		r++;

	}
	return cnt1*cnt2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> str;
	int l = str.length();
	LL ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '@') 
			ans += getans(i);
	}
	cout << ans << endl;
	return 0;
}