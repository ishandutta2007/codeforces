#include<bits/stdc++.h>
using namespace std;
#define N 2222
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
inline bool Solve(){
	n=read();
	int t=0;
	for(int i=1;i<=n;++i){
		t^=(a[i]=read());
	}
	if(!t)return true;
	int cnt=0,now=0;
	for(int i=1;i<=n;++i){
		now^=a[i];
		if(now==t){
			++cnt;
			now=0;
		}
	}
	return cnt>=3;	
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"YES\n":"NO\n");	
	}
	return 0;
}