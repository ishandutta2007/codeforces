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
class mirror
{
public:
	long long l, r;
	long long s;
	bool operator < (mirror& m)
	{
		return l < m.l;
	}
	mirror(long long _l, long long _r, long long _s)
	{
		l = _l;
		r = _r;
		s = _s;
	}
};
vector<mirror> vm[2];
int f[2][102];
int main()
{

	//cin.rdbuf(fin.rdbuf());
	long long h1, h2;
	long long n;
	cin >> h1 >> h2 >> n;
	long long c, l, r;
	char ch;
	const long long aa = 100000;
	for (int i = 0; i < n; i++)
	{
		cin >> c >> ch >> l >> r;
		if (ch == 'T') vm[1].push_back(mirror(l, r, c));
		else vm[0].push_back(mirror(l, r, c));
	}
	vm[0].push_back(mirror(aa + 1, aa + 2, 0));
	vm[1].push_back(mirror(aa + 1, aa + 2, 0));
	sort(vm[0].begin(), vm[0].end());
	sort(vm[1].begin(), vm[1].end());
	long long ans = 0;
	long long tmp = 0;
	long long h = h1;
	for (int i = 0; i < 300; i++)
	{
		if (i % 2 == 0) h = i * 100 + h2 + h1;
		else h = i * 100 + 100 - h2 + h1;
		int k[2];
		k[0] = k[1] = 0;
		tmp = 0;
		int flag;
		MEM(f, 0);
		for (int j = 0; j <= i; j++)
		{
			long long tt = (h1 + j * 100) * aa;
			int t = j & 1;
			flag = 0;
			for (; k[t] < vm[t].size(); )
			{
				if (tt > vm[t][k[t]].l * h && tt < vm[t][k[t]].r * h)
				{
					tmp += vm[t][k[t]].s;
					flag = 1;
					if (f[t][k[t]] == 1)
					{
						flag = 0;
						break;
					}
					f[t][k[t]] = 1;
					k[t]++;
					break;
				}
				k[t]++;
			}
			if (!flag) break;
		}
		if (flag)
		{
			ans = MAX(ans, tmp);
		}
	}
	h1 = 100 - h1;
	h2 = 100 - h2;
	swap(vm[0], vm[1]);
	for (int i = 0; i < 300; i++)
	{
		if (i % 2 == 0) h = i * 100 + h2 + h1;
		else h = i * 100 + 100 - h2 + h1;
		int k[2];
		k[0] = k[1] = 0;
		tmp = 0;
		int flag;
		MEM(f, 0);
		for (int j = 0; j <= i; j++)
		{
			long long tt = (h1 + j * 100) * aa;
			int t = j & 1;
			flag = 0;
			for (; k[t] < vm[t].size(); )
			{
				if (tt > vm[t][k[t]].l * h && tt < vm[t][k[t]].r * h)
				{
					tmp += vm[t][k[t]].s;
					flag = 1;
					if (f[t][k[t]] == 1)
					{
						flag = 0;
						break;
					}
					f[t][k[t]] = 1;
					k[t]++;
					break;
				}
				k[t]++;
			}
			if (!flag) break;
		}
		if (flag)
		{
			ans = MAX(ans, tmp);
		}
	}
	cout << ans << endl;

	return 0;
}