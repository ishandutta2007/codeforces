#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

const int size = 200 * 1000;

bool used[size];
int min_div[size], used_by[size];

int main() {
	int n, m, p, num, flag;
	char tp;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		used[i] = false;
		used_by[i] = -1;
		min_div[i] = -1;
	}
	for (int i = 2; i <= n; i++)
		if (min_div[i] == -1)
		{
			min_div[i] = i;
			for (int j = 2; i * j <= n; j++)
				if (min_div[i * j] == -1)
					min_div[i * j] = i;
		}
	for (int i = 0; i < m; i++)
	{
		scanf("%c%d\n", &tp, &num);
		if (tp == '+')
		{
			if (used[num])
			{
				printf("Already on\n");
				continue;
			}
			p = num;
			flag = -1;
			while (p != 1)
			{
				if (used_by[min_div[p]] != -1)
				{
					flag = used_by[min_div[p]];
					break;
				}
				p /= min_div[p];
			}
			if (flag != -1)
			{
				printf("Conflict with %d\n", flag);
				continue;
			}
			p = num;
			while (p != 1)
			{
				used_by[min_div[p]] = num;
				p /= min_div[p];
			}
			used[num] = true;
			printf("Success\n");
		}
		else
		{
			if (!used[num])
			{
				printf("Already off\n");
				continue;
			}
			p = num;
			while (p != 1)
			{
				used_by[min_div[p]] = -1;
				p /= min_div[p];
			}
			used[num] = false;
			printf("Success\n");
		}
	}

	return 0;
}