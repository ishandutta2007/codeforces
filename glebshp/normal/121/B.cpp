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

const int size = 1000 * 1000;

char buf[size];

int main()
{
	int n, k, p;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	
	scanf("%d%d\n", &n, &k);
	scanf("%s", buf);
	p = 0;
	while (p < n)
	{
		if (p == n - 1 || buf[p] != '4' || buf[p + 1] != '7' || k == 0)
			p++;
		else
		{
			if (!(p % 2))
			{
				buf[p] = '4';
				buf[p + 1] = '4';
				k--;
			}
			else
			{
				if (buf[p - 1] == '4')
					k %= 2;
				if (k > 0)
				{
				buf[p] = '7';
				buf[p + 1] = '7';
				p--;
				k--;
				}
			}
		}
	}
	printf("%s", buf);

    return 0;
}