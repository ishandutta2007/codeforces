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
int T,n,a[N],b[N],A[101],B[101];
inline int calc(int *a,int n){
	int ans=0;
	for(int i=100;i>=0;--i){
		if(a[i]>=n){
			return ans+n*i;
		}
		else{
			n-=a[i];
			ans+=a[i]*i;	
		}
	}
	return ans;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	for(int i=1;i<=n;++i){
		b[i]=read();
	}
	memset(A,0,sizeof(A));
	memset(B,0,sizeof(B));
	for(int i=1;i<=n;++i){
		++A[a[i]],++B[b[i]];
	}
	if(calc(A,n-n/4)>=calc(B,n-n/4)){
		printf("0\n");
		return;
	}
	for(int i=n+1;;++i){
		++A[100],++B[0];
		if(calc(A,i-i/4)>=calc(B,i-i/4)){
			printf("%d\n",i-n);
			return;
		}	
	}
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}