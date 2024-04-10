#include <stdio.h>
#define maxN 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int n,k,tmp,bx[maxN],i; bool cn;
int main(){
	n=getint(); k=getint();
	for( i=1;i<=n;bx[i]=getint(),i++ );
	for( i=k+1;i<=n;i++ ) if( bx[i]!=bx[k] ) cn=true;
	if(!cn){
		for( i=k-1;i;i-- ) if( bx[i]!=bx[k] ) break;
	}
	printf("%d\n",cn?-1:i);
}