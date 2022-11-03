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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const int INF = 0x3f3f3f3f;
const int N = 1020;

int main()
{
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << 0;
		for(int i = 1; i < n; i++)
		{
			cout << ' ' << i;
		}
		cout << endl;
		cout << 0;
		for(int i = 1; i < n; i++)
		{
			cout << ' ' << i;
		}
		cout << endl;
		cout << 0;
		for(int i = 1; i < n; i++)
		{
			cout << ' ' << (i+i)%n;
		}
		cout << endl;
	}
	return 0;

}