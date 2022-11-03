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
ifstream fin("ab.txt");
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MEM(a,b) (memset((a),(b),sizeof(a)))

int main()
{
	long long a,b,c;
	cin >> a >> b >> c;
	long long pro = a*b*c;
	long long d,e,f;
	d = sqrt(double(pro/a/a));
	e = sqrt(double(pro/b/b));
	f = sqrt(double(pro/c/c));
	cout << 4*(d+e+f) << endl;
	return 0;
}