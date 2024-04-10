#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000
using namespace std;
int n,tot,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,500000){int ii=i;
		while(ii%5==0)n--,ii/=5;
		if(n==0)a[++tot]=i;
	}
	printf("%d\n",tot);
	rep(i,1,tot)printf("%d ",a[i]);
}