#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int m=300000;
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
class BIT{
protected:
	ll b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	inline void Add(int x,int d){
		++x;
		while(x<=m+1)b[x]+=d,x+=lowbit(x);
	}
	inline ll Ask(int x){
		ll ans=0;
		++x;
		x=min(x,m+1);
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}	
}B,T;
int n,a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	ll ans=0,sum=0;
	for(int i=1;i<=n;++i){
		ans+=sum+1LL*a[i]*(i-1)-B.Ask(a[i]);
		sum+=a[i];
		for(int j=a[i];j<=m;j+=a[i]){
			ans-=1LL*j*(T.Ask(j+a[i]-1)-T.Ask(j-1));
			B.Add(j,j),B.Add(j+a[i],-j);
		}
		T.Add(a[i],1);
		printf("%lld ",ans);	
	}
	return 0;
}