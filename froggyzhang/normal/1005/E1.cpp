#include<bits/stdc++.h>
using namespace std;
#define N 200010
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
int n,m,a[N];
struct BIT{
	int b[N<<1];
	void clear(){memset(b,0,sizeof(b));}
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x){
		while(x<=(n<<1|1))++b[x],x+=lowbit(x);
	}	
	inline int Ask(int x){
		int ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
ll Solve(ll x){
	B.clear();
	B.Add(n+1);
	int now=0;
	ll ans=0;
	for(int i=1;i<=n;++i){
		now+=a[i]>=x?1:-1;
		ans+=B.Ask(now+n-1+1);
		B.Add(now+n+1);
	}
	return ans;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();	
	}
	printf("%lld\n",Solve(m)-Solve(m+1));
	return 0;
}