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
	string str;
	string tmp = "bear";
	cin >> str;
	int l = str.length();
	int pre = 0;
	int ans = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')
		{
			int flag = 1;

			for (int j = 1; j < 4 && i + j < l; j++)
			{
				if (str[j + i] != tmp[j]) flag = 0;
			}
			if (i + 3 >= l) flag = 0;
			if (flag)
			{
				ans += (i - pre + 1)*(l - (i + 4)+1);
				pre = i + 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}