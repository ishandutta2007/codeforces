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
const double eps = 1e-10;


int main()
{
	//freopen("input.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	int tot = 0;
	int k = m;
	int x;
	while (n--)
	{
		cin >> x;
		if (k >= x) k -= x;
		else tot++, k = m - x;
	}
	cout << tot + 1 << endl;
	return 0;
}