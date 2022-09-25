#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
int main(){
	printf("? %d\n",200*200);
	for(int i=1;i<=200;++i){
		for(int j=1;j<=200;++j){
			printf("%d %d ",i,j);		
		}
	}
	printf("\n");fflush(stdout);
	int S=read();
	int l=1,r=8,ans=256,p=0;
	while(l<r){
		int mid=(l+r)>>1;
		int t=1<<mid;
		printf("? %d\n",200/t*200);
		for(int i=t;i<=200;i+=t){
			for(int j=1;j<=200;++j){
				printf("%d %d ",i,j);		
			}
		}
		printf("\n");
		fflush(stdout);
		int x=read();
		if(t*x==S)l=mid+1;
		else r=mid,ans=t,p=x;
	}
	int A=abs(S/(ans>>1)-(p<<1))-1;
	int B=S/(A+1)-1;
	printf("! %d\n",(A+B)<<1);
	fflush(stdout);
	return 0;
}