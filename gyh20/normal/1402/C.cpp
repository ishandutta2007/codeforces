#include<cstdio>
int n,m,M=1e9+7;
int ksm(int x,int y,int s=1){for(;y;y>>=1,x=1ll*x*x%M)if(y&1)s=1ll*s*x%M;return s;}
int main(){
	scanf("%d%d",&n,&m);
	printf("%d",1ll*(n+1-m)*ksm(n+1,M-2)%M*ksm(2*n+2,m)%M);
}