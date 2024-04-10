#include <stdio.h>
#include <algorithm>
struct XD{
	int no,v;
}bx[1001];
int n,k;
bool cmp( XD x , XD y ){ return x.v > y.v; }
int main(){
	freopen("input.txt","r",stdin);       
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&k);
	for( int i=0;i<n;i++ ) bx[i].no=i+1,scanf("%d",&bx[i].v);
	std::sort( bx , bx+n , cmp );
	printf("%d\n",bx[k-1].v);
	for( int i=0;i<k;printf("%d ",bx[i].no),i++ ); puts("");
	return 0;
}