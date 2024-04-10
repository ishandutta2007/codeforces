#include <stdio.h>
#define min(x,y) (x<y?x:y)
int bx[10],a,b,c;
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int main(){
	for( int i=1;i<=8;bx[i]=getint(),i++ );
	a=bx[2]*bx[3]/bx[7]; b=bx[4]*bx[5]; c=bx[6]/bx[8];
	a/=bx[1]; b/=bx[1]; c/=bx[1]; 
	printf("%d\n",min(a,min(b,c)));
}