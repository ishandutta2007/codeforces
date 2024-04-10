#include <stdio.h>
#include <stdlib.h>
#define N 110
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int min( int x , int y ){ return x<y?x:y; }
int r[N],c[N],n,r1,c1,r2,c2,ans;
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	n=getint();
	for( int i=1;i<=n;i++ ) r[i]=getint();
	r1=getint(); c1=getint(); r2=getint(); c2=getint();
	c[r1]=c1;
	for( int i=r1-1;i;i-- ) c[i]=min(c[i+1],r[i]+1);
	for( int i=r1+1;i<=n;i++ ) c[i]=min(c[i-1],r[i]+1);
	ans=abs(r1-r2)+abs(c[r2]-c2);
	if( c[r2]<=c2 ) return printf("%d\n",ans),0;
	for( int i=1;i<=n;i++ ) ans=min(ans,abs(r1-i)+abs(r2-i)+abs(c[i]-c2));
	printf("%d\n",ans);
	
	fclose(fin); fclose(fout);
}