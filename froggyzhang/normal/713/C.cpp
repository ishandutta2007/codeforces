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
int n;
ll ans;
priority_queue<int> q;
int main(){
	n=read();
	//  x=0  
	for(int i=1;i<=n;++i){
		int x=read()-i;
		q.push(x);
		ans+=x; 
		if(q.top()>x)q.pop(),q.push(x);
	}
	while(!q.empty())ans-=q.top(),q.pop(); // 
	printf("%lld\n",ans);
	return 0;
}