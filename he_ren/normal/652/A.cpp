#include<cstdio>
#include<cstdlib>

inline int cl(int a,int b){ return (a+b-1)/b;}
inline void print(int x){ printf("%d",x); exit(0);}

int main(void)
{
	int h1,h2,a,b;
	scanf("%d%d%d%d",&h1,&h2,&a,&b);
	
	if(h1+8*a >= h2) print(0);
	if(a <= b) print(-1);
	print( cl( h2-h1-8*a, 12*(a-b) ) );
	return 0;
}