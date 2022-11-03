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
ifstream fin("aa.txt");
#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MEM(x,y) (memset((x),(y),sizeof(x)))


int main()
{
	int n;
	cin >> n;
	if(n&1) cout << -1 << endl;
	else
	{
		cout << 2;
		for(int i = 2; i <= n; i++)
		{
			cout << ' ';
			if(i&1) cout << i+1;
			else cout << i-1;
		}
		cout << endl;
	}
	return 0;
}