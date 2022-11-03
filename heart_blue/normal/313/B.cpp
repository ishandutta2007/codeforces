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

int main()
{
	int n;
	string str;
	cin >> str;
	int a[100002];
	MEM(a,0);
	int l = str.length();
	for(int i = 2; i <= l; i++)
	{
		a[i] += a[i-1] + (str[i-1] == str[i-2]);
	}
	a[l+1] = a[l];

	int x,y;
	cin >> n;
	while(n--)
	{
		cin >> x >> y;
		cout << a[y] - a[x] << endl;
	}
    return 0;

}