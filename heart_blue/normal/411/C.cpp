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

bool check(int a, int b, int c, int d)
{
	return a > d && b > c;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int a1, a2, b1, b2, c1, c2, d1, d2;
	cin >> a1 >> b2 >> a2 >> b1;
	cin >> c1 >> d2 >> c2 >> d1;
	if ((check(a1, b1, c1, d1) && check(a1, b1, c2, d2)) ||
		(check(a2, b2, c1, d1) && check(a2, b2, c2, d2)))
	{
		cout << "Team 1" << endl;
	}
	else if ((check(c1, d1, a1, b1) || check(c2, d2, a1, b1)) &&
		(check(c1, d1, a2, b2) || check(c2, d2, a2, b2)))
	{
		cout << "Team 2" << endl;
	}
	else cout << "Draw" << endl;
	return 0;
}