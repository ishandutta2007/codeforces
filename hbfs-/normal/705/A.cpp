#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) {
		if (i%2 == 1) printf("I hate ");else printf("I love ");
		if (i == n) printf("it\n");else printf("that ");
	}
	return 0;
}