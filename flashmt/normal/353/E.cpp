#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

char edge[1000100];
int n, inDeg[1000100], outDeg[1000100];

int calc(vector <int> c, int C)
{
	int res = 1, must = 0;
	c[1]--;
	for (int i = 1; i + 1 < C; i++)
		if (c[i] || must)
		{
			c[i + 1]--;
			must = 0;
			res++;
		}
		else must = 1;
		
	must |= c[C - 1] > 0;
	
	return res + must;
}

int main()
{
	scanf("%s", &edge);
	n = strlen(edge);
	
	for (int i = 0; i < n; i++)
	{
		int j = (i + 1) % n;
		if (edge[i] == '0') outDeg[i]++, inDeg[j]++;
		else inDeg[i]++, outDeg[j]++;
	}
	
	vector <int> chainLength;
	for (int i = 0; i < n; i++)
		if (!inDeg[i]) 
		{
			rotate(edge, edge + i, edge + n);
			for (int j = 0; j < n; )
			{
				int k = j;
				while (k < n && edge[k] == edge[j]) k++;
				chainLength.push_back(k - j);
				j = k;
			}
			break;
		}
		
	//for (int i = 0; i < int(chainLength.size()); i++) cout << chainLength[i] << ' ';
	
	for (int i = 0; i < int(chainLength.size()); i++)
		if (chainLength[i] > 1)
		{
			rotate(chainLength.begin(), chainLength.begin() + i, chainLength.end());
			break;
		}
		
	int C = chainLength.size();
	if (C == 2)
	{
		if (chainLength[0] == 1 || chainLength[1] == 1) puts("1");
		else puts("2");
		return 0;
	}
	
	int minimumChain = calc(chainLength, C);
	reverse(chainLength.begin(), chainLength.end());
	minimumChain = min(minimumChain, calc(chainLength, C));
		
	cout << minimumChain << endl;
}