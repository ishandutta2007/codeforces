#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int Q,f[N];
ll ans[N];
vector<pair<int,int> > A[N];
class BIT{
	ll b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
public:
	void Add(int x,int d){
		while(x<=200000)b[x]+=d,x+=lowbit(x);	
	}
	inline ll Ask(int x){
		ll ans=0;
		while(x)ans+=b[x],x-=lowbit(x);
		return ans;
	}
}B;
void init(int n){
	for(int i=1;i<=n;++i){
		for(int j=i+i;j<=n;j+=i){
			f[j]++;
		}
	}
	for(int i=1;i<=n;++i){
		B.Add(i,f[i]*(f[i]-1)/2);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(200000);
	cin>>Q;
	for(int i=1;i<=Q;++i){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		ans[i]=1LL*len*(len-1)*(len-2)/6;
		ans[i]-=max(0,r/6-(l*2-1)/6);
		ans[i]-=max(0,r/15-((l*5+1)/2-1)/15);
		A[l].emplace_back(r,i);
	}
	for(int i=1;i<=200000;++i){
		for(auto [j,id]:A[i]){
			ans[id]-=B.Ask(j);
		}
		for(int j=i+i;j<=200000;j+=i){
			B.Add(j,-f[j]+1);
			--f[j];
		}
	}
	for(int i=1;i<=Q;++i){
		cout<<ans[i]<<'\n';
	}
	return 0;
}