#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue> 
#define maxn 500005
#define mxhash 10
using namespace std;

int n;
int len[maxn];
int bg[maxn], ed[maxn];
char inp[maxn * 2];

int main()
{
	scanf("%d", &n);
	bg[0] = 0;
	for(int i = 0; i < n; i++)
	{
		scanf("%s", inp + bg[i]);
		for(int j = bg[i]; j < maxn * 2; j++)
			if(inp[j] == '\0') 
			{
				bg[i + 1] = j, ed[i] = j - 1;
				break;
			}
	}
	for(int i = n - 2; i >= 0; i--)
	{
		int lst = -1;
		for(int j = 0; j <= min(ed[i + 1] - bg[i + 1], ed[i] - bg[i]); j++)
		{
			if(inp[bg[i] + j] < inp[bg[i + 1] + j])
			{
				lst = ed[i] - bg[i];
				break;
			}
			if(inp[bg[i] + j] == inp[bg[i + 1] + j]) lst++;
			else break; 
		}
	//	cout<<i<<" "<<bg[i]<<" "<<ed[i]<<endl;
		ed[i] = bg[i] + lst;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = bg[i]; j <= ed[i]; j++)
			printf("%c", inp[j]);
		printf("\n");
	}
	return 0;
}