#include <stdio.h>
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int md[]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int cnt[1000],n,m,d,p,t,rd,max;
int main(){

	FILE *fin,*fout;
	fin = freopen("input.txt","r",stdin);
	fout = freopen("output.txt","w",stdout);

	n=getint(); while( n-- ){
		m=getint(); d=getint(); p=getint(); t=getint(); rd=md[m]+d;
		for( int i=1;i<=t;i++ ){
			cnt[rd+401-i]+=p;
		}
	}
	for( int i=0;i<1000;i++ ) if( cnt[i]>max ) max=cnt[i];
	printf("%d\n",max);

	fclose(fin); fclose(fout);
}