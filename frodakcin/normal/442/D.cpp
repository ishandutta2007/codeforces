#include <iostream>
#include <cstdio>

using namespace std;

const int MN = 1e6 + 100;
int N;
int p[MN], d[MN], h[MN], f;
void work(int n, int v)
{
	if(v > f)
		f = v;
	if(n==1) return;
	if(v > h[n])
	{
		h[n] = v;
		if(d[n] < v)
			work(p[n], d[n]=v);
	}
	else if(v == h[n])
		if(d[n] == v)
			work(p[n], d[n]=v+1);
}
int main(void)
{
	scanf("%d", &N);
	for(int i = 2;i <= N+1;i++)
		scanf("%d", p + i), work(i, 0), printf("%d\n", f);
	return 0;
}