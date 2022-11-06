#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define add(x,y) x=(x+(y))%998244353
using namespace std;
int n,k;long long a[1010][2010][4],ans;
int main(){
	scanf("%d%d",&n,&k);
	a[1][1][0]=a[1][1][3]=a[1][2][1]=a[1][2][2]=1;
	rep(i,2,n)rep(j,0,k)rep(k1,0,3)rep(k2,0,3)
		if((k1!=k2)&&(k1%3)&&(k2%3))add(a[i][j+2][k2],a[i-1][j][k1]);
		else if((k1==k2)||(((k1^k2)<3)&&(!(k2%3))))add(a[i][j][k2],a[i-1][j][k1]);
		else add(a[i][j+1][k2],a[i-1][j][k1]);
	rep(i,0,3)add(ans,a[n][k][i]);
	printf("%I64d",ans);
}