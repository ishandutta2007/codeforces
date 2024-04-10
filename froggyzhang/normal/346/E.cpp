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
int n,A,p,d,T,a[N];
int calc(int A,int n,int p){
	if(1LL*A*n<p)return max(A,p-A*n);
	int _A=A-p%A,_n=1LL*n*A/p-(1LL*A*n%p<1LL*A*(p/A-1)),_p=A;
	return calc(_A,_n,_p);
}
bool Solve(){
	A=read(),n=read(),p=read(),d=read();
	A%=p;
	return (1LL*A*n<p?A:calc(A,n,p))<=d;
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");
	}
	return 0;
}