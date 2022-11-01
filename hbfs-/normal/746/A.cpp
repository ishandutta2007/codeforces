#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int t = min(a,b/2);
	t = min(t,c/4);
	printf("%d\n",t*7);
	return 0;
}