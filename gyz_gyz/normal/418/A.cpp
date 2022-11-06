#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	if(n<=k*2){
		printf("-1\n");return 0;
	}
	printf("%d\n",n*k);
	rep(i,1,n)
		rep(j,1,k){
			int r=i+j;if(r>n)r-=n;
			printf("%d %d\n",i,r);
		}
}