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
map<int, vector<int> > mv;
char ch[3000][3000];
int main()
{
	//freopen("input.txt", "r", stdin);
	LL n;
	char c[3] = "/\\";
	int a[2] = { 1, -1 };
	MEM(ch, 0);
	int x = 1500;
	int y = 0;
	cin >> n;
	int minx = x;
	int maxx = x;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		while (t--)
		{
			ch[x][y] = c[i & 1];
			y++;
			x -= a[i & 1];
		}
		x += a[i & 1];
		minx = min(minx, x);
		maxx = max(maxx, x);
	}
	for (int i = minx; i <= maxx; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (ch[i][j]) putchar(ch[i][j]);
			else putchar(' ');
		}
		puts("");
	}
	return 0;
}