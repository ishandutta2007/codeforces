#include <stdio.h>
#define maxN 1010
#define swap(x,y) {int t=x;x=y;y=t;}
#define FOR(i,j,k) for(int i=j;i<=k;i++)
int bx[maxN][maxN],c[maxN],r[maxN],n,m,qx,qy,k; char ch;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	FOR(i,1,n)FOR(j,1,m)scanf("%d",&bx[i][j]);
	FOR(i,1,n)r[i]=i; FOR(i,1,m)c[i]=i;
	while( k-- ){
		ch=getchar(); while( ch<'a'||ch>'z' ) ch=getchar();
		scanf("%d %d",&qx,&qy);
		if( ch=='g' ) printf("%d\n",bx[r[qx]][c[qy]]);
		else if( ch=='c' ){ swap(c[qx],c[qy]); }
		else{ swap(r[qx],r[qy]); }
	}
	return 0;
}