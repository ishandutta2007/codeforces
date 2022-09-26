#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <iomanip>

using namespace std;

int n,k,depth,len;
int path[25],x,y;

bool ask(int a,int b,int c)
{
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	cout.flush();
	string res;
	cin >> res;
	return res == "Yes";
}

bool cmp(const int &a,const int &b)
{
	return ask(x,a,b);
}

int main()
{
	srand(time(0));
	cin >> n >> k;
	int cur = 1;
	for (depth = 0;;depth++)
	{
		cur *= k;
		if (cur > n)
			break;
	}
	while (1)
	{
		x = rand() % n + 1,y = rand() % n + 1;
		while (x == y)
			x = rand() % n + 1,y = rand() % n + 1;
		len = 0;
		for (int i = 1;i <= n;i++)
			if (i != x && i != y && ask(x,i,y))
				path[++len] = i;
		if (len == depth * 2 - 1)
			break;
	}
	nth_element(path + 1,path + depth,path + len + 1,cmp);
	cout << "! " << path[depth] << endl;
	cout.flush();
	return 0;
}