#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define PI 3.1415926535897932384626433832795

const long long inf = 1000ll * 1000 * 1000;
const int size = 100;

long long smb, n, k;
int ans;
bool used[size];
int perm[size];


void genthemall(long long num)
{
	if (num > inf)
		return;
	if (num <= n - 15 && num >= 1)
		ans++;
	genthemall(num * 10 + 4);
	genthemall(num * 10 + 7);
}

bool islucky(long long num)
{
	if (num == 0)
		return false;
	while (num > 0)
	{
		if (num % 10 != 4 && num % 10 != 7)
			return false;
		num /= 10;
	}
	return true;
}

int main()
{

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	cin >> n >> k;
	long long fct = 1;
	int h = min(n, 15ll), i, j;
	for (i = 1; i <= h; i++)
		fct *= i;
	if (fct < k)
	{
		cout << -1 << endl;
		return 0;
	}
	smb = 15;
	ans = 0;
	genthemall(0);
	for (i = 0; i < h; i++)
		used[i] = false;
	for (i = 0; i < h; i++)
	{
		fct /= (h - i);
		for (j = 0; j < h; j++)
			if (!used[j])
				if (fct >= k)
				{
					used[j] = true;
					perm[i] = j; 
					break;
				}
				else
					k -= fct;
		ans += islucky(n - h + i + 1) && islucky(n - h + perm[i] + 1);
	}
	cout << ans << endl;

    return 0;
}