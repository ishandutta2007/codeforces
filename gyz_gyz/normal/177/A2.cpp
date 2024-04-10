#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
int n,a[200][200],ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d",&a[i][j]);
	if(n==1){printf("%d\n",a[1][1]);return 0;}
	rep(i,1,n)ans+=a[i][i]+a[i][n-i+1]+a[i][(n+1)/2]+a[(n+1)/2][i];
	ans-=a[(n+1)/2][(n+1)/2]*3;printf("%d\n",ans);
}