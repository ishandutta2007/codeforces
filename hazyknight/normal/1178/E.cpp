#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

const int MAXN = 1000005;

int n;

char s[MAXN];

vector<int> front,back;

void solve(int l,int r)
{
	if (r - l + 1 <= 3)
	{
		front.push_back(l);
		return;
	}
	for (int i = l;i <= l + 2;i++)
		for (int j = r;j >= r - 2;j--)
			if (i - l + r - j <= 2 && s[i] == s[j])
			{
				front.push_back(i);
				back.push_back(j);
				solve(i + 1,j - 1);
				return;
			}
}

int main()
{
	scanf("%s",s + 1);
	n = strlen(s + 1);
	solve(1,n);
	for (int i = 0;i < front.size();i++)
		printf("%c",s[front[i]]);
	for (int i = back.size() - 1;i >= 0;i--)
		printf("%c",s[back[i]]);
	puts("");
	return 0;
}