#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 10000
using namespace std;
int n,x,a[N],b[N],c[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,n)if(a[i]==b[i])c[a[i]]=1,x++;
	if(x==n-1){
		rep(i,1,n)if(!c[i])x=i;
		rep(i,1,n)if(a[i]!=b[i])a[i]=x;
	}else{
		rep(i,1,n)if(a[i]!=b[i])
			if(c[a[i]])a[i]=b[i],c[a[i]]=1;
		rep(i,1,n)if(a[i]!=b[i])
			if(c[b[i]])b[i]=a[i],c[a[i]]=1;
		rep(i,1,n)if(a[i]!=b[i]){
			if(c[a[i]])a[i]=b[i];c[a[i]]=1;
		}
	}
	rep(i,1,n)printf("%d ",a[i]);
}