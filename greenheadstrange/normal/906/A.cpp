#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 100005
using namespace std;
bool can[27];
char inp[maxn];
bool hv[27];
int main()
{
	int n;
	for(int i = 0; i < 27; i++)
		can[i] = 1;
	scanf("%d", &n);
	bool flag = 0;
	int cnts = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		char ns[3];
		scanf("%s", ns);
		scanf("%s", inp);	
		int l = strlen(inp);
		if(ns[0] == '.')
		{
			for(int j = 0; j < l; j++)
				can[inp[j] - 'a'] = 0;
		}
		else if(ns[0] == '!')
		{
			if(flag) cnts++;
			for(int i = 0; i < 27; i++)
				hv[i] = 0;
			for(int j = 0; j < l; j++)
				hv[inp[j] - 'a'] = 1;
			for(int i = 0; i < 27; i++)
				if(!hv[i])
					can[i] = 0;
		}
		else
		{
			if(i != n && flag) 
				cnts++;
			can[inp[0] - 'a'] = 0;
		}
		if(!flag)
		{
			int cnt = 0;
			for(int i = 0; i < 26; i++)
				if(can[i])
					cnt++, ans = i;
			if(cnt <= 1)
				flag = 1;
		}
	}	
	printf("%d\n", cnts);
	return 0;
}