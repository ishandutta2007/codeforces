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
	//freopen("input.txt","r",stdin);
	int a,b,c;
	int n;
	cin >> n;
	int cnt = 0;
	for(int c = n; c > 0; c--)
	{
		for(int b = c-1; b > 0; b--)
		{
			int d = c*c-b*b;
			int a = sqrt(double(d));
			if(a > b) break;
			if(a*a == d)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}