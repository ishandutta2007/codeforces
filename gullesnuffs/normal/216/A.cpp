
#include <stdio.h>

using namespace std;

int main()
{
	int A, B, C, ans=1;
	scanf("%d%d%d", &A, &B, &C);
	int a=1, b=1, c=1;
	while(a < A){
		++a;
		ans += b+c-1;
	}
	while(b < B){
		++b;
		ans += a+c-1;
	}
	while(c < C){
		++c;
		ans += a+b-1;
	}
	printf("%d", ans);
	return 0;
}