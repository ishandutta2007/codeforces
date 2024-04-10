#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define maxn 26
using namespace std;
int cnt[maxn];
int main()
{
	int k;
	scanf("%d", &k);
	for(int i = 0; i < maxn; i++)
	{
		for(int j = 0; j * (j - 1) / 2 <= k; j++)
			cnt[i] = j;
		k -= cnt[i] * (cnt[i] - 1) / 2;
		for(int j = 0; j < cnt[i]; j++)
			printf("%c", char('a' + i));
	} 
	printf("\n");
}