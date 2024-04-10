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

bool check(string str)
{
	if (str.length() < 5) return false;
	int flag = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (isupper(str[i])) flag |= 1;
		if (isdigit(str[i])) flag |= 2;
		if (islower(str[i])) flag |= 4;
	}
	return flag == 7;
}
int main()
{
	string str;
	cin >> str;
	if (check(str)) cout << "Correct" << endl;
	else cout << "Too weak" << endl;
	return 0;
}