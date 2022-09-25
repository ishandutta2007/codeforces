#include<bits/stdc++.h>
using namespace std;
#define N 300030
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
	q.push(-read());
	for(int i=2;i<=n;++i){
		int x=read();
		int t=q.top();
		if(x+t>0){
			q.pop();
			ans+=x+t;
			q.push(-x);
		}
		q.push(-x);
	}
	printf("%lld\n",ans);
	return 0;
}