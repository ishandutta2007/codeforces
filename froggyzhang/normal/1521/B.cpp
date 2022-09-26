#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
inline int Find(int x,int y){
	for(int i=x+1;;++i){
		if(__gcd(i,x)==1&&__gcd(i,y)==1)return i;
	}
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	printf("%d\n",n-1);
	for(int i=1;i<n;++i){
		int mn=min(a[i],a[i+1]);
		int gg=Find(mn,i==1?1:a[i-1]);
		printf("%d %d %d %d\n",i,i+1,gg,mn);
		a[i]=gg,a[i+1]=mn;
	}	
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}