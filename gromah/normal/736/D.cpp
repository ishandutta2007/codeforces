#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define M 100 + 5
#define K 500000 + 5

int n, m, E[K][2];

struct Bitset
{
	unsigned int num[M];
	void Modify(int x)
	{
		x --;
		num[x >> 5] ^= 1 << (x & 31);
	}
	int Query(int x)
	{
		x --;
		return (num[x >> 5] >> (x & 31)) & 1;
	}
	void Xor(Bitset a)
	{
		for (int i = 0; (i << 5) <= n; i ++)
			num[i] ^= a.num[i];
	}
}A[N], B[N];

inline void Gauss()
{
	int k = 0;
	for (int i = 1; i <= n; i ++)
	{
		int j = k + 1;
		for (; j <= n && !A[j].Query(i); j ++) ;
		if (j > n) continue ;
		k ++;
		swap(A[k], A[j]);
		swap(B[k], B[j]);
		for (int l = 1; l <= n; l ++)
			if (l != k && A[l].Query(i))
			{
				A[l].Xor(A[k]);
				B[l].Xor(B[k]);
			}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d%d", E[i], E[i] + 1);
		A[E[i][0]].Modify(E[i][1]);
	}
	for (int i = 1; i <= n; i ++)
		B[i].Modify(i);
	Gauss();
	for (int i = 1; i <= m; i ++)
		puts(B[E[i][1]].Query(E[i][0]) ? "NO" : "YES");
	return 0;
}