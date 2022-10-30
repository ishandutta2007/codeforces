#include <stdio.h>
#define maxN 100001
int bx[maxN],l[maxN],r[maxN],n,ans,tmp;
int getint(){
	int x=0,tmp=1; char c=getchar();
	while( (c<'0'||c>'9')&&c!='-' ) c=getchar();
	if( c=='-' ) c=getchar(),tmp=-1;
	while(c>='0'&&c<='9') x*=10,x+=(c-'0'),c=getchar();
	return x*tmp;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&n); bx[0]=bx[n+1]=0; ans=n;
	for( int i=1;i<=n;scanf("%d",&bx[i]),i++ );
	for( int i=1;i<=n;i++ ) l[i]=l[i-1]+(bx[i]>=0);
	for( int i=n;i>1;i-- ){
		r[i]=r[i+1]+(bx[i]<=0); tmp=l[i-1]+r[i];
		ans = ans<tmp?ans:tmp;
	}
	printf("%d\n",ans);
	return 0;
}