#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
int n,ans;
int main(){
	scanf("%d",&n);ans=1;
	rep(i,2,n){
		if(i*i>n)break;
		while(n%i==0)ans+=n,n/=i;
	}
	if(n>1)ans+=n;printf("%d\n",ans);
}