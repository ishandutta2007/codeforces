#include <cstdio>
#include <cassert>
#include <vector>

#define HIDE

const int BOUND = 2.5e5;
int N;
#ifndef HIDE
int a[100];
#endif

std::vector<int> ans;
void addop(int i)
{
	i %= N;
	ans.push_back(i);
#ifndef HIDE
	a[i] ^= a[(i+1)%N];
#endif
}

/*
 * TOO SLOW
 *
void transfer(int a, int b) // b changed, a unchanged
{
	for(int i=b;i<a;++i)
		addop(i);
	for(int i=a-2;i>=b;--i)
		addop(i);

	for(int i=b+1;i<a;++i)
		addop(i);
	for(int i=a-2;i>b;--i)
		addop(i);
}
void swap(int i, int j) // i < j
{
	if(i+N-j < j-i)
	{
		transfer(i+N, j);
		transfer(j, i);
		transfer(i+N, j);
	}
	else
	{
		transfer(j, i);
		transfer(i+N, j);
		transfer(j, i);
	}
}
*/
void chain(int a, int b)
{
	for(int i=a-1;i>=b;--i)
		addop(i);
	for(int i=b+1;i<a;++i)
		addop(i);
}
void swap(int i, int j) // i < j
{
	for(int k=0;i+k<j-k;++k)
		chain(j-k, i+k);
	for(int k=i;k<(i+j)/2;++k)
		addop(k);
}

int main()
{
	scanf("%d", &N);
#ifndef HIDE
	for(int i=0;i<N;++i) a[i] = 1<<i;
#endif

	swap(0, N-1);
	swap((N+1)/2, N/2+N-1);
	swap(0, N-1);
	
	assert(ans.size() < BOUND);
	printf("%u\n", ans.size());
	for(int i=0;i<ans.size();++i)
		printf("%d%c", ans[i], " \n"[i+1==ans.size()]);

#ifndef HIDE
	for(int i=0;i<N;++i) printf("%d: %d\n", i, a[i]);
#endif
	return 0;
}