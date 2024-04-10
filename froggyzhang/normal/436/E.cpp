#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
const ll inf=0x3f3f3f3f3fll;
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
int n,m;
ll a[N],b[N];
int c[N];
ll ans;
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q1,q2,q3,q4,q5;
int main(){
	n=read(),m=read();
	q1.push({inf,0}),q2.push({inf,0}),q3.push({inf,0}),q4.push({inf,0}),q5.push({inf,0});
	for(int i=1;i<=n;++i){
		a[i]=read(),b[i]=read();
		q1.push({a[i],i});
		q3.push({b[i],i});
	}
	while(m--){
		while(q1.top().second&&c[q1.top().second]^0)q1.pop();
		auto [t1,p1]=q1.top();
		while(q2.top().second&&c[q2.top().second]^1)q2.pop();
		auto [t2,p2]=q2.top();
		while(q3.top().second&&c[q3.top().second]^0)q3.pop();
		auto [t3,p3]=q3.top();
		while(q4.top().second&&c[q4.top().second]^2)q4.pop();
		auto [t4,p4]=q4.top();
		while(q5.top().second&&c[q5.top().second]^1)q5.pop();
		auto [t5,p5]=q5.top();
		ll mn=min(min(t1,t2),min(t3+t4,t3+t5));
		ans+=mn;
		if(t1==mn){
			q1.pop();
			++c[p1];
			q2.push({b[p1]-a[p1],p1});
			q5.push({-a[p1],p1});
		}
		else if(t2==mn){
			q2.pop();
			++c[p2];
			q4.push({a[p2]-b[p2],p2});
		}
		else if(t3+t4==mn){
			q3.pop(),q4.pop();
			c[p3]+=2,--c[p4];
			q4.push({a[p3]-b[p3],p3});
			q2.push({b[p4]-a[p4],p4});
			q5.push({-a[p4],p4});
		}
		else if(t3+t5==mn){
			q3.pop(),q5.pop();
			c[p3]+=2,--c[p5];
			q4.push({a[p3]-b[p3],p3});
			q1.push({a[p5],p5});
			q3.push({b[p5],p5});
		}
		else assert(false);
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		putchar(c[i]+'0');
	}
	return 0;
}