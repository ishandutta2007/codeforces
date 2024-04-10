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
int n,las,T;
void Solve(){
	n=read(),las=0;
	for(int i=1;i<=n;++i){
		int x=read(),t=0;
		for(int j=0;j<30;++j){
			if(las>>j&1&&!(x>>j&1))t|=1<<j;	
		}
		printf("%d ",t);
		las=t|x;
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