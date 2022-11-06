#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define mx 2000000
using namespace std;
int n,al,s,a[2000],v[mx+1],p[mx];
int main(){
	rep(i,2,mx){
		if(!v[i])p[++al]=i;
		rep(j,1,al){
			if(p[j]*i>mx)break;
			v[p[j]*i]=1;
			if(i%p[j]==0)break;
		}
	}
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)if(a[i]==1)s++;
	if(s)rep(i,1,n)if(a[i]!=1&&!v[a[i]+1]){
		printf("%d\n",s+1);
		rep(j,1,s)printf("1 ");
		printf("%d\n",a[i]);return 0;
	}
	if(s>1){
		printf("%d\n",s);
		rep(i,1,s)printf("1 ");return 0;
	}
	rep(i,1,n)rep(j,i+1,n)if(!v[a[i]+a[j]]){
		printf("2\n%d %d\n",a[i],a[j]);return 0;
	}
	printf("1\n%d\n",a[1]);
}