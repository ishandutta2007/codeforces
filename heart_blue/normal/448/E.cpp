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
#pragma comment(linker,"/STACK:102400000,102400000") 
vector<LL> v[7000];
map<LL, int> m;
int n;
void dfs(int t, LL k)
{
	if (n == 0) return;
	if (k == 0)
	{
		cout << v[t].back() << ' ';
		n--;
		return;
	}
	
	cout << 1 << ' ';
	n--;
	if (n == 0) return;
	for (int i = 1; i < v[t].size(); i++)
	{
		if (n == 0) return;
		if (v[t].size() == 2)
		{
			LL s = k-1;
			while (s--)
			{
				cout << 1 << ' ';
				n--;
				if (n == 0) return;
			}
			cout << v[t][i] << ' ';
			n--;
			if (n == 0) return;
			continue;
		}
		else dfs(m[v[t][i]], k - 1);
		if (n == 0) return;
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	LL x, k;
	cin >> x >> k;
	for (LL i = 1; i*i <= x; i++)
	{
		if (x%i) continue;
		v[0].push_back(i);
		if (i != x / i) v[0].push_back(x / i);

	}
	sort(v[0].begin(), v[0].end());
	for (int i = 0; i < v[0].size() - 1; i++)
	{
		m[v[0][i]] = i+1;
		for (int j = 0; j <= i; j++)
		{
			if(v[0][i]%v[0][j] == 0) v[i + 1].push_back(v[0][j]);
		}
	}
	if (k == 0)
	{
		cout << x << endl;
		return 0;
	}
	if (x == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	n = 1e5;
	dfs(0, k);
	return 0;
}