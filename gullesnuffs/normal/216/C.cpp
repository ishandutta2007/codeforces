#include <stdio.h>

using namespace std;

int ans=0;

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if(n == m && n == 2 && k == 1)
		printf("%d\n", k*2+2);
	else if(n == m || (n == m+1 && k == 1))
		printf("%d\n", k*2+1);
	else
		printf("%d\n", k*2);
	printf("1");
	for(int i=0; i < k-1; ++i)
		printf(" 1");
	printf(" %d", n);
	for(int i=0; i < k-1; ++i)
		printf(" %d", n+1);
	if(n == m){
		if(n == 2 && k == 1)
			printf(" %d", n+1);
		printf(" %d", n+2);
	}
	if(n == m+1 && k == 1)
		printf(" %d", n+1);
	return 0;
}