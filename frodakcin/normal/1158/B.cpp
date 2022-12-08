#include <iostream>
#include <cstdio>

using namespace std;

int N, K, L, c;
int main(void)
{
	scanf("%d%d", &N, &K); L = N-K+3>>1;
	for(int i = 0;i < N;) printf("%d", !(++i%L)); printf("\n");
	return 0;
}