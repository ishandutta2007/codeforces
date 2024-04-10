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
int T,n,m;
int Solve(){
	int ans=0x3f3f3f3f;
	for(int i=0;i<=30;++i){
		if(m+i==1)continue;
		int tmp=i;
		int x=n;
		while(x)++tmp,x/=m+i;
		ans=min(ans,tmp);
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read(),m=read();
		printf("%d\n",Solve());
	}
	return 0;
}