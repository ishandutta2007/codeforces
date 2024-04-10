#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector> 
#define maxn 1000005
using namespace std;
string inp[maxn];
int nx[maxn * 2], frs[maxn], eds[maxn], to[maxn * 2];
bool ipa[maxn];
int egcnt = 0;
void addedge(int u, int v)
{
	ipa[v] = false;
	int nows = egcnt;
	egcnt++;
	to[nows] = v, nx[nows] = -1;
	if(frs[u] != -1)
	{
		nx[eds[u]] = nows;
		eds[u] = nows;
	}
	else
		frs[u] = eds[u] = nows;
}
int stack[maxn], epl = -1;
int stnum[maxn];
char input[maxn];
int q[maxn][2], fr = 0, ed = 0;
int root;
int bgpl[maxn], edpl[maxn];
char all[maxn];
int alpl = 0;
void bfs()
{
	q[ed][0] = root, q[ed++][1] = 0;
	while(fr < ed)
	{
		int top = q[fr][0];
		for(int k = frs[top]; k != -1; k = nx[k])
		{
			q[ed][0] = to[k];
			q[ed][1] = q[fr][1] + 1;
			ed++;
		}
		fr++;
	}
	printf("%d\n", q[ed - 1][1]);
	int ndep = 1;
	for(int i = 1; i < ed; i++)
	{
		if(q[i][1] > ndep) 
			printf("\n"), ndep = q[i][1];
		for(int j = bgpl[q[i][0]]; j <= edpl[q[i][0]]; j++)
			printf("%c", all[j]);
		printf(" ");
	}
}

int main()
{
	scanf("%s", input);
	memset(frs, -1, sizeof(frs));
	memset(eds, -1, sizeof(eds));
	memset(nx, -1, sizeof(nx));
	int nword = 0;
	int ntype = 0;// 0 word, 1 number
	int nownum = 0;
	for(int i = 0; i < maxn; i++)
		ipa[i] = true;
	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i] == ',')
		{
			if(ntype) 
			{
				if(nownum != 0)
				{
					epl++;
					stack[epl] = nword - 1;
					stnum[epl] = nownum;
				}
				nownum = 0;
				ntype = 0;
				bgpl[nword] = alpl;
			}
			else
			{
				if(epl != -1)
				{
					addedge(stack[epl], nword);
					stnum[epl]--;
					if(stnum[epl] == 0)
						epl--;
				}	
				edpl[nword] = alpl - 1;
				nword++;
				ntype = 1;
				
			}
		}
		else
		{
			if(ntype)
				nownum *= 10, nownum += int(input[i] - '0');
			else
				all[alpl] = input[i], alpl++;
		}
	}
	root = nword + 1;
	for(int i = 0; i < nword; i++)
		if(ipa[i])
			addedge(root, i);
	bfs();
	
	return 0;
}