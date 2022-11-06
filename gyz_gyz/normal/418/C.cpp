#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int a[101],b[101],n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(n==2){a[1]=3;a[2]=4;}
	else if(n%2){
		a[1]=2;a[n]=(n+1)/2;
		rep(i,2,n-1)a[i]=1;
	}else{
		a[n]=(n-2)/2;
		rep(i,1,n-1)a[i]=1;	
	}
	if(m==2){b[1]=3;b[2]=4;}
	else if(m%2){
		b[1]=2;b[m]=(m+1)/2;
		rep(i,2,m-1)b[i]=1;
	}else{
		b[m]=(m-2)/2;
		rep(i,1,m-1)b[i]=1;	
	}
	rep(i,1,n){
		rep(j,1,m)printf("%d ",a[i]*b[j]);
		printf("\n");
	}
}