#include <stdio.h>
int n,bd; char c[101];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%s",&n,c); bd = n>>1;
	for( int i=0;i<bd;i++ ){
		if( c[i]=='R'&&c[i+bd]=='L' ) printf("%d %d\n",i+bd+1,i+1);
		else printf("%d %d\n",i+1,i+bd+1);
	}
	return 0;
}