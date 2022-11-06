#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 1000001
using namespace std;
int a[mx],n,j;long long x,y,k;char c[mx];
int main(){
	scanf("%d%I64d%s",&n,&k,c+1);
	rep(i,2,n){
		for(j=a[i-1];j&&c[j+1]!=c[i];)j=a[j];
		if(c[j+1]!=c[i])a[i]=0;else a[i]=j+1;
	}
	rep(i,1,n){
		x=i-a[i];y=i/x-(i/x%k)*(k+1);
		if(i%x)if(y-k>=0)printf("1");else printf("0");
		else if(y>=0)printf("1");else printf("0");
	}
}