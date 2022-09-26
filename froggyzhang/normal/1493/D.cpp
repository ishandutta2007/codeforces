#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=1e9+7;
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
int n,Q,a[N],ans;
map<int,int> mp[N];
void Add(int x,int w,int d){
	mp[w][x]+=d;
	if(mp[w].size()==n){
		static vector<int> vec;
		vec.clear();
		int mn=233333333;
		for(auto [u,t]:mp[w])mn=min(mn,t);
		for(int i=1;i<=mn;++i)ans=1LL*ans*w%mod;
		for(auto &[u,t]:mp[w]){
			t-=mn;
			if(!t)vec.push_back(u);
		}
		for(auto u:vec){
			mp[w].erase(u);
		}
	}
}
void Mul(int x,int w){
	if(w==1)return;
	int tp=w;
	for(int i=2;i*i<=tp;++i){
		if(tp%i==0){
			int cnt=0;
			while(tp%i==0)++cnt,tp/=i;
			Add(x,i,cnt);
		}
	}
	if(tp>1)Add(x,tp,1);
}
int main(){
	n=read(),Q=read();
	ans=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		Mul(i,a[i]);
	}
	while(Q--){
		int i=read(),x=read();
		Mul(i,x);
		printf("%d\n",ans);
	}	
	return 0;
}