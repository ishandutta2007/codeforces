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
int T;
ll n;
//#define mak akioi
ll C,las;
set<ll> vis;
inline int Ask(ll x){
	cout<<"? "<<x<<endl;
	#ifdef mak
	assert(!vis.count(x));
	assert(x>=1&&x<=n);
	vis.insert(x);
	ll t=llabs(x-las);
	las=x;
	return t>=C;
	#endif
	return read();
}
inline void Report(ll x){
	cout<<"= "<<x<<endl;
}
mt19937 rnd(time(0));
void Solve(){
	n=read();
//	n=rnd()%100000+1;
	#ifdef mak
	C=read();
//	C=rnd()%n+1;
	las=0;
	vis.clear();
	#endif
//	cerr<<" n: "<<n<<" C: "<<C<<endl;
	static vector<ll> p;
	p.clear();
	ll tmp=0;
	while(tmp+1<n){
		tmp=(tmp+n)>>1;
		p.push_back(tmp);
	}
	ll now=1,t=1;
	while(!p.empty()){
		t?now+=p.back():now-=p.back();
		t^=1;	
		p.pop_back();
	}
	if(!t)t=1,now=n-now+1;
	Ask(now);
	ll ans=n,l=0,r=n;	
	while(l+1<r){
		ll mid=(l+r)>>1;
		t?now+=mid:now-=mid;
		t^=1;
		if(Ask(now)){
			r=ans=mid;	
		}
		else{
			l=mid;
		}
	}
	Report(ans);
	#ifdef mak
	assert(ans==C);
	#endif
}
int main(){
	T=read();
	while(T--){
		Solve();	
	}
	return 0;
}