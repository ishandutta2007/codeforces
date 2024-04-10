#include<cstdio>

int main(void)
{
	putchar('?');
	for(int i=1; i<=100; ++i) printf(" %d",i);
	putchar('\n'); fflush(stdout);
	int x;
	scanf("%d",&x);
	
	putchar('?');
	for(int i=1; i<=100; ++i) printf(" %d",i<<7);
	putchar('\n'); fflush(stdout);
	int y;
	scanf("%d",&y);
	
	printf("! %d\n",((x>>7)<<7) |  (y&((1<<7)-1)));
	//fflush(stdout);
	return 0;
}