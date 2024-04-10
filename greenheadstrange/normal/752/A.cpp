#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	int nows = (k - 1) / (2 * m);
	k -= nows * (2 * m);
	nows++;
	int n1 = (k + 1) / 2;
	printf("%d %d ", nows, n1);
	if(k % 2) printf("L");
	else printf("R");
	
}