#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>

using namespace std;

int n,cnt;
int a[1000005];

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	int i = 1,j;
	while (i <= n)
	{ 
		if (a[i] == i)
			i++;
		else
		{
			cnt++;
			int tmp = a[i];
			swap(a[i],a[tmp]);
		}
	}
	i = (3 * n) / cnt;
	j = (3 * n) % cnt;
	if (!(i & 1) || (j & 1))
		cout << "Um_nik" << endl;
	else
		cout << "Petr" << endl;
	return 0;
}