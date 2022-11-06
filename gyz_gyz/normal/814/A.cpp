#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 1000
using namespace std;
int n,k,x,a[N];
int main(){
	scanf("%d%d",&n,&k);
	if(k>1){printf("Yes");return 0;}
	rep(i,1,n)scanf("%d",&a[i]);
	scanf("%d",&x);
	rep(i,1,n){
		if(!a[i])a[i]=x;
		if((i>1)&&(a[i]<a[i-1])){
			printf("Yes");return 0;
		}
	}
	printf("No");
}