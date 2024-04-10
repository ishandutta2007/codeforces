#include <stdio.h>
#define maxN 100010
int getint(){
	int x=0; char c=getchar();
	while( c<'0'||c>'9' ) c=getchar();
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x;
}
int bx[maxN],l[maxN],r[maxN],cnt[maxN],ans[maxN],tmp[maxN],n,m;
int main(){
	n=getint(); m=getint();
	for( int i=1;i<=n;i++ ){
		bx[i]=getint();
		if( bx[i]<maxN ) cnt[bx[i]]++;
	}
	for( int i=0;i<m;i++ ) l[i]=getint(),r[i]=getint();
	for( int i=1;i<=n;i++ ) if( cnt[i]>=i ){
		for( int j=1;j<=n;j++ ) tmp[j]=tmp[j-1]+(bx[j]==i);
		for( int j=0;j<m;j++ ) ans[j]+=( tmp[r[j]]-tmp[l[j]-1]==i );
	}
	for( int i=0;i<m;printf("%d\n",ans[i]),i++ );
}