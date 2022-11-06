#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000000
using namespace std;
int n,m,x,p,a[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&x);
		if(x==1)a[m++]=p,p=1;else p++;
	}
	a[m]=p;printf("%d\n",m);
	rep(i,1,m)printf("%d ",a[i]);
}