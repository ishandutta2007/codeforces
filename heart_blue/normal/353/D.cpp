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
string str;
int main()
{
	int n;
	//freopen("input.txt","r",stdin);
	int sum = 0;
	cin >> str;
	n = str.length();
	int ans = 0;
	for(int i = 0; i < str.length(); i++)
	{
		if(str[i] == 'M') continue;
		if(i == sum) {sum++;continue;};
		
		int t = i - sum;
		sum ++;
		if(t > ans) {ans = t; continue;};
		ans ++;
	}
	cout << ans << endl;
	return 0;
}