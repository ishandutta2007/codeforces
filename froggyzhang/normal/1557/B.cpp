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
int T,n,k,a[N],p[N];
bool Solve(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i]=i;		
	}
	sort(p+1,p+n+1,[&](int i,int j){return a[i]<a[j];});
	int tmp=0;
	for(int i=1;i<n;++i){
		if(p[i+1]!=p[i]+1)++tmp;
	}
	return k>=tmp+1;
	
}
int main(){
	T=read();
	while(T--){
		printf(Solve()?"Yes\n":"No\n");	
	}
	return 0;
}