#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define N 233
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
int T,n,a[N];
void Solve(){
	if(n&1){
		for(int i=1;i<n-3;i+=2){
			printf("%d %d ",a[i+1],-a[i]);
		}
		for(int x=-100;x<=100;++x){
			for(int y=-100;y<=100;++y){
				int z=x*a[n-2]+y*a[n-1];
				if(z%abs(a[n])==0){
					printf("%d %d %d\n",x,y,z/a[n]);
					return;
				}
			}
		}
	}
	else{
		for(int i=1;i<n;i+=2){
			printf("%d %d ",a[i+1],-a[i]);
		}
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		Solve();
	}
	return 0;
}