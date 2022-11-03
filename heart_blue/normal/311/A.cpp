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

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	cin >> n >> k;
	if(n*(n-1)/2 <= k) cout << "no solution" << endl;
	else
	{
		for(int i = 0; i < n; i++)
		{
			cout << 0 << ' ' << i << endl;
		}
	}
	return 0;
}