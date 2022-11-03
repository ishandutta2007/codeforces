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

LL getans(LL n, int k)
{
	int len[20];
	int pos = 0;
	while (n)
	{
		len[pos++] = n % 10;
		n /= 10;
	}
	for (int i = pos - 1; i >= 0; i--)
	{
		int maxv = -1;
		int t = -1;
		for (int j = i; j >= 0 && j + k >= i; j--)
		{
			if (len[j] > maxv) maxv = len[j], t = j;
		}
		while (t < i)
		{
			swap(len[t], len[t+1]);
			t++;
			k--;
			if (k == 0) break;
		}
		if (k == 0) break;
	}
	LL ret = 0;
	for (int i = pos - 1; i >= 0; i--)
	{
		ret = ret * 10 + len[i];
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	LL n;
	int k;
	cin >> n >> k;
	cout << getans(n, k) << endl;
	return 0;
}