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
mt19937 rnd(time(0));
int n,T,a[55];
inline bool check(){
	a[0]=a[2*n];
	a[2*n+1]=a[1];
	for(int i=1;i<=2*n;++i){
		if(a[i]*2==a[i-1]+a[i+1])return false;
	}
	return true;	
}
void Solve(){
	n=read();
	for(int i=1;i<=2*n;++i){
		a[i]=read();
	}
	while(!check()){
		shuffle(a+1,a+2*n+1,rnd);
	}
	for(int i=1;i<=(n<<1);++i){
		printf("%d ",a[i]);
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