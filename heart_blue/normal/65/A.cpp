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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

const int INF = 1e6 + 3;
const int N = 1e3 + 1;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	LL a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	if (c == 0)
	{
		if (d != 0)
		{
			cout << "Ron" << endl;
			return 0;
		}
	}
	if (a == 0 && b != 0 && d != 0)
	{
		cout << "Ron" << endl;
		return 0;
	}
	if (b*d*f > a*c*e) cout << "Ron" << endl;
	else cout << "Hermione" << endl;
	return 0;
}