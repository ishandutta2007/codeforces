#include<bits/stdc++.h>
using namespace std;
#define N 10010
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
int n,a[N],T;
void Solve(){
	n=read();
	int p=-1;
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	a[n+1]=1;
	for(int i=0;i<=n;++i){
		if(!a[i]&&a[i+1]){p=i;break;}
	}
	for(int i=0;i<=n;++i){
		if(i)printf("%d ",i);
		if(i==p)printf("%d ",n+1);	
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}