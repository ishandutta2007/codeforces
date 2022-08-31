#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define re register
using namespace std;
int t,n,a,b,c;
int v[1002];
int ans;
signed main(){
scanf("%d",&t);
while(t--){
	ans=(1<<30);
	memset(v,0,sizeof(v));
	scanf("%d%d%d",&n,&a,&b);
	for(re int i=1;i<=b;++i){
		scanf("%d",&c);
		if(abs(c-a)<=1000)++v[abs(c-a)];
	}
	for(re int i=a;i<=1000;++i)++v[i];
	for(re int i=n-a+1;i<=1000;++i)++v[i];
	if(!v[0])ans=0;
	else{
		for(re int i=1;i<=1000;++i)if(v[i]<2){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
}
	}