// Codeforces Beta Round #25
// Problem E -- Test
#include <cstdio>
#include <cstring>
#include <climits>

#define N 300001
#define M 26

using namespace std;

int mask[N], fail[N], trie[N][M], queue[N << 3], dp[N][1 << 3];
char str[N];

int main()
{
	int size = 1;
	memset(mask, 0, sizeof(mask));
	memset(trie, 0, sizeof(trie));
	for(int i = 0; i != 3; ++ i)
	{
		scanf("%s", str);
		int len = strlen(str), cur = 0;
		for(int j = 0; j != len; cur = trie[cur][str[j] - 'a'], ++ j)
			if(!trie[cur][str[j] - 'a'])
				trie[cur][str[j] - 'a'] = size ++;
		mask[cur] |= 1 << i;
	}
	memset(fail, 0, sizeof(fail));
	int head = 0, tail = 0;
	for(int i = 0; i != M; ++ i)
		if(trie[0][i])
			queue[tail ++] = trie[0][i];
	while(head != tail)
	{
		int cur = queue[head ++];
		mask[cur] |= mask[fail[cur]];
		for(int i = 0; i != M; ++ i)
			if(trie[cur][i])
				fail[trie[cur][i]] = trie[fail[cur]][i], queue[tail ++] = trie[cur][i];
			else
				trie[cur][i] = trie[fail[cur]][i];
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0, queue[0] = 0, head = 0, tail = 1;
	while(head != tail)
	{
		int cur = queue[head] >> 3, sta = queue[head] & 7;
		for(int i = 0; i != M; ++ i)
		{
			int new_cur = trie[cur][i], new_sta = sta | mask[new_cur];
			if(dp[new_cur][new_sta] == -1)
			{
				dp[new_cur][new_sta] = dp[cur][sta] + 1;
				if(new_sta == 7)
				{
					printf("%d\n", dp[new_cur][new_sta]);
					return 0;
				}
				queue[tail ++] = (new_cur << 3) | new_sta;
			}
		}
		head ++;
	}
}