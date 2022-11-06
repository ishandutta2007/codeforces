#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, W[N], Go[N][3], Op[N], Ans[N]; // AND = 1, OR = 2, XOR = 3, NOT = 4

int ALU(int op, int T[3])
{
	if (op == 1) return (W[T[1]] & W[T[2]]);
	else if (op == 2) return (W[T[1]] | W[T[2]]);
	else if (op == 3) return (W[T[1]] ^ W[T[2]]);
	else return !W[T[1]];
}

void dfs(int z)
{
	for (int i = 1; i <= Go[z][0]; i ++)
		dfs(Go[z][i]);
	if (Op[z]) W[z] = ALU(Op[z], Go[z]);
}

void dfs(int z, bool able)
{
	if (!Go[z][0])
	{
		Ans[z] = W[1] ^ able;
		return ;
	}
	for (int i = 1; i <= Go[z][0]; i ++)
	{
		if ((Op[z] == 1 && W[Go[z][3 - i]] == 0) || (Op[z] == 2 && W[Go[z][3 - i]] == 1))
			dfs(Go[z][i], 0);
		else dfs(Go[z][i], able);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		string str;
		cin >> str;
		if (str == "IN") scanf("%d", W + i);
		else if (str == "NOT")
		{
			Op[i] = 4;
			Go[i][0] = 1;
			scanf("%d", Go[i] + 1);
		}
		else
		{
			Op[i] = (str == "AND" ? 1 : (str == "OR" ? 2 : 3));
			Go[i][0] = 2;
			scanf("%d%d", Go[i] + 1, Go[i] + 2);
		}
	}
	dfs(1);
	dfs(1, 1);
	for (int i = 1; i <= n; i ++)
		if (!Go[i][0]) putchar(48 + Ans[i]);
	puts("");
	return 0;
}