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

const int size = 10 * 1000;

char buf[size];
int smb[256];
bool good[size];

bool prime(int val)
{
	int i = 2;
	while (i * i <= val)
	{
		if (val % i == 0)
			return false;
		i++;
	}
	return true;
}

int main()
{
	int len, cnt, i, j, mx;

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

	scanf("%s", buf);
	len = strlen(buf);
	cnt = 1;
	good[0] = true;;
	for (i = 1; i < len; i++)
		if (prime(i + 1) && (i + 1) * 2 > len)
		{
			cnt++;
			good[i] = true;
		}
	for (i = 0; i < len; i++)
		smb[buf[i]]++;
	mx = 0;
	for (i = 0; i < 256; i++)
		if (smb[i] > smb[mx])
			mx = i;
	if (smb[mx] >= len - cnt)
	{
		printf("YES\n");
		for (i = 0; i < len; i++)
			if (!good[i])
			{
				buf[i] = mx;
				smb[mx]--;
			}
		for (i = 0; i < len; i++)
			if (good[i])
				for (j = 0; j < 256; j++)
					if (smb[j] > 0)
					{
						buf[i] = j;
						smb[j]--;
						break;
					}
		printf("%s\n", buf);
	}
	else
		printf("NO\n");

    return 0;
}