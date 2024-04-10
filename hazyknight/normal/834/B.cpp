#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

int n,k;
int last[1000005];

bool mark[30];

string a;

int main()
{
	cin >> n >> k >> a;
	for (int i = 0;i < a.size();i++)
		last[a[i] - 'A'] = i;
	int now = 0;
	for (int i = 0;i < a.size();i++)
	{
		if (!mark[a[i] - 'A'])
			mark[a[i] - 'A'] = true,now++;
		if (i > 0 && last[a[i - 1] - 'A'] == i - 1)
			mark[a[i - 1] - 'A'] = false,now--;
		if (now > k)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl; 
	return 0;
}