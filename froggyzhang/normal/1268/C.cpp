#include<bits/stdc++.h>
//#include<bits/extc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp> //tree
using namespace std;
using namespace __gnu_pbds;
#define N 200020
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
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;
int n,p[N];
struct BIT{
	ll b[N];
	inline int lowbit(int x){return x&(-x);}
	inline void Add(int x,int d){
		while(x<=n)b[x]+=d,x+=lowbit(x);
	}
	inline ll Ask(int x){
		ll ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}A,B;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		p[read()]=i;	
	}
	ll tmp=0;
	for(int i=1;i<=n;++i){
		int u=p[i];
		B.Add(u,u);
		tmp+=i-1-A.Ask(u);
		A.Add(u,1);
		t.insert(u);
		ll md=*t.find_by_order(i>>1);
		ll l=(i>>1)+1,r=i-l+1;
		printf("%lld ",tmp+l*md-B.Ask(md)-l*(l-1)/2+r*(n-md+1)-(n*r-(B.Ask(n)-B.Ask(md-1)-r))-r*(r-1)/2);
	}
	return 0;
}