#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int mod;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
class Union_Set{
public:
	int f[N],siz[N];
	inline int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}
	void init(int n){
		for(int i=1;i<=n;++i){
			f[i]=i,siz[i]=1;
		}
	}
	void Merge(int x,int y){
		int fx=getf(x),fy=getf(y);
		if(fx==fy)return;
		f[fy]=fx;
		siz[fx]+=siz[fy];
	}
}S;
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>mod;
	S.init(n);
	for(int i=1;i<=m;++i){
		int x,y;
		cin>>x>>y;
		S.Merge(x,y);
	}
	int cnt=0,ans=1;
	for(int i=1;i<=n;++i){
		if(S.f[i]==i){
			ans=1LL*ans*S.siz[i]%mod;
			++cnt;
		}
	}
	if(cnt==1){
		cout<<1%mod<<'\n';return 0;
	}
	ans=1LL*ans*qpow(n,cnt-2)%mod;
	cout<<ans<<'\n';
	return 0;
}