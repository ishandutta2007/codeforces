
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
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MEM(a,b) (memset((a),(b),sizeof(a)))

int main()
{
	int x = -1;
	int y = -1;
	int n;
	int a,b;
	cin >> n;
	int cnt = 1;
	int ans = 1;
	while(n--)
	{
		cin >> a >> b;
		if(a == x && b== y)
		{
			cnt ++;
			ans = MAX(cnt,ans);
		}
		else
		{
			cnt = 1;
			x = a;
			y = b;
		}
	}
	cout << ans << endl;
	return 0;
}