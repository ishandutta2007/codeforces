#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define maxw 4
#define maxsum 10000
using namespace std;
int ask[12], ans[8][2];
int as = 0, bs = 0;
void get(int x, int y)
{
	
	int a[maxw];
	int nows = x;
	for(int k = 0; k < maxw; k++)
	{
		a[k] = nows % 10;
		nows /= 10;
	}
	int b[maxw];
	nows = y;
	for(int i = 0; i < maxw; i++)
	{
		b[i] = nows % 10;
		nows /= 10;
	}
	as = bs = 0;
	for(int i = 0; i < maxw; i++)
		if(a[i] == b[i]) as++;
	for(int i = 0; i < maxw; i++)
		for(int j = 0; j < maxw; j++)
		{
			if(i == j) continue;
			if(a[i] == b[j]) 
				bs++;
		}
}
int q[maxsum], fr = 0, ed = 0;
int nums[maxsum][(maxw + 1) * (maxw + 1)];
int main()
{
	memset(ask, 0, sizeof(ask));
	ask[0] = 1234;
	for(int i = 0; i < 8; i++)
	{
		if(!ask[i])
		{
			fr = ed = 0;
			if(ans[i - 1][0] == maxw) break;
			for(int j = 0; j < maxsum; j++)
			{
				bool flag = true;
				int a[maxw];
				int nows = j;
				for(int k = 0; k < maxw; k++)
				{
					a[k] = nows % 10;
					nows /= 10;
				}
				for(int k = 0; k < maxw; k++)
					for(int l = k + 1; l < maxw; l++)
						if(a[k] == a[l]) 
							flag = false;
				
				if(!flag) continue;
				for(int m = 0; m < i; m++)
				{
					get(ask[m], j);
					if(as != ans[m][0]) flag = false;
					if(bs != ans[m][1]) flag = false;
				} 
				if(flag)
					q[ed++] = j;
			}
			memset(nums, 0, sizeof(nums));
			for(int k = 0; k < ed; k++)
				for(int j = k + 1; j < ed; j++)
				{
					get(q[k], q[j]);
					nums[k][as * (maxw + 1) + bs]++;
					nums[j][as * (maxw + 1) + bs]++;
				}
			int mins = -1, minpl = 0;
			for(int k = 0; k < ed; k++)
			{
				int nmxs = 0;
				for(int j = 0; j < (maxw + 1) * (maxw + 1); j++)
					nmxs = max(nmxs, nums[k][j]);
				if(nmxs < mins || mins == -1)
					minpl = k, mins = nmxs;
			}
			ask[i] = q[minpl];
		}
		int nows = ask[i];
		int a[maxw];
		for(int i = 0; i < maxw; i++)
		{
			a[i] = nows % 10;
			nows /= 10;
		}
		for(int i = maxw - 1; i >= 0; i--)
			printf("%d",a[i]);
		printf("\n");
		fflush(stdout);
		scanf("%d%d", &ans[i][0], &ans[i][1]);
	}
	
}