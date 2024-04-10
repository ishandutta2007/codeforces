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
	int l,r;
	l = r = 0;
	int a,b;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		l += a;
		r += b;
	}
	l = MIN(l,n-l);
	r = MIN(r,n-r);
	cout << r+l << endl;
	return 0;
}