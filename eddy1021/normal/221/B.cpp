#include <stdio.h>
bool v[10];
int f(int x){ for(;x;x/=10) if(v[x%10]) return true; return false; }
int n,ans,i,tmp;
int main(){
	scanf("%d",&n); tmp=n; ans=0; for(;tmp;tmp/=10) v[tmp%10]=true;
	for( i=1;i*i<=n;i++ ) if( !(n%i) ) ans+=f(i)+(i*i<n&&f(n/i));
	printf("%d\n",ans);
}