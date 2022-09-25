#include<bits/stdc++.h>
using namespace std;
#define N 800080
typedef long long ll;
const ll inf=0x3f3f3f3f3f3fll;
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
vector<pair<ll,ll> > a;
priority_queue<ll,vector<ll>,less<ll> > A;  // 
priority_queue<ll,vector<ll>,greater<ll> > B;  // 
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),y=read();
		a.emplace_back(x+y,x-y);
	}
	sort(a.begin(),a.end());
	for(auto [x,y]:a){
		ll L=(A.empty()?-inf:A.top())-x,R=(B.empty()?inf:B.top())+x;
		ans+=x+y;
		if(y>=L&&y<=R){
			A.push(x+y),B.push(y-x);	
		}
		else if(y<L){
			A.pop(),A.push(x+y),A.push(x+y),B.push(L-x);
		}
		else{
			B.pop(),B.push(y-x),B.push(y-x),A.push(R+x);	
		}
	}
	while(!A.empty())ans-=A.top(),A.pop();
	printf("%lld\n",ans/2); 
	return 0;
}