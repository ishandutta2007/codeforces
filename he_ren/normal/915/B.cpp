#include<cstdio>
#include<cstdlib>

inline int min(int a,int b){ return a<b? a: b;}
inline int Abs(int x){ return x<0? -x: x;}
inline void print(int x){ printf("%d",x); exit(0);}

int main(void)
{
	int n,pos,l,r;
	scanf("%d%d%d%d",&n,&pos,&l,&r);
	
	int dl=Abs(pos-l), dr=Abs(pos-r);
	if(l==1 && r==n) print(0);
	if(l==1) print(dr+1);
	if(r==n) print(dl+1);
	print( min(dl,dr)+r-l+2 );
	return 0;
}