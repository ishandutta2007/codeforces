#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 200000
int n,m,c,t,a[N],b[N];
int main(){
	scanf("%d%d%d",&n,&m,&c);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,m)scanf("%d",&b[i]);
	rep(i,1,n){
		if(i<=m)t+=b[i];
		printf("%d ",(a[i]+t)%c);
		if(i-n+m>0)t-=b[i-n+m];
	}
}