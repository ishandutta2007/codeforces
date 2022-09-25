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
int n,m;
vector<ll> A,B;
bool Solve(){
	if(n==1)return true;
	ll u=0;
	A.clear();
	ll all=(1LL<<n)-1;
	A.push_back(0);
	for(int i=1;i<=m;++i){
		B.clear();
		ll z=0;
		int k=read();
		vector<int> pos;
		for(int j=0;j<k;++j){
			int tmp=read()-1;
			z|=1LL<<tmp;
			pos.push_back(tmp);
		}
		reverse(pos.begin(),pos.end());
		static ll h[44];
		for(int i=1;i<=(int)pos.size();++i){
			h[i]=h[i-1]|(1LL<<pos[i-1]);	
		}
		ll d=z^(z&u);
		int t=__builtin_popcountll(d);
		for(int j=0;j<=t;++j){
			for(auto x:A){
				int cnt=j+__builtin_popcountll(x&z);
				B.push_back((x&(all^z))|h[cnt]);
			}
		}
		u|=d;
		swap(A,B);
		sort(A.begin(),A.end());
		A.erase(unique(A.begin(),A.end()),A.end()); 
	}
	if(u^all)return false;
	for(auto x:A){
		for(int i=0,ok=0;i<n;++i){
			if(x>>i&1)ok=1;
			else if(ok)return false;
		}	
	}
	return true;
}
int main(){
	n=read(),m=read();
	printf(Solve()?"ACCEPTED\n":"REJECTED\n");
	return 0;
}