#include<bits/stdc++.h>
using namespace std;
#define N 500050
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,a[N],p[N],dp[N];
ll s[N],b[N],len;
class BIT1{
	int b[N];
public:
	void init(int n){
		for(int i=1;i<=n;++i){
			b[i]=-inf;
		}
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x<=len)b[x]=max(b[x],d),x+=lowbit(x);
	}
	inline int Ask(int x){
		int ans=-inf;
		while(x)ans=max(ans,b[x]),x-=lowbit(x);
		return ans;
	}
}B1;
class BIT2{
	int b[N];
public:
	void init(int n){
		for(int i=1;i<=n;++i){
			b[i]=-inf;
		}
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x)b[x]=max(b[x],d),x-=lowbit(x);
	}
	inline int Ask(int x){
		int ans=-inf;
		while(x<=len)ans=max(ans,b[x]),x+=lowbit(x);
		return ans;
	}
}B2;
map<int,int> mp;
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	len=0;
	for(int i=0;i<=n;++i){
		b[++len]=s[i];
	}
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=0;i<=n;++i){
		p[i]=lower_bound(b+1,b+len+1,s[i])-b;
	}
	dp[0]=0;
	B1.init(len);
	B2.init(len);
	B1.Add(p[0],0);
	B2.Add(p[0],0);
	mp.clear();
	mp[p[0]]=0;
	for(int i=1;i<=n;++i){
		dp[i]=-inf;
		if(mp.count(p[i])){
			dp[i]=mp[p[i]];
		}
		dp[i]=max(dp[i],B1.Ask(p[i]-1)+i);
		dp[i]=max(dp[i],B2.Ask(p[i]+1)-i);
		if(!mp.count(p[i]))mp[p[i]]=dp[i];
		else mp[p[i]]=max(mp[p[i]],dp[i]);
		B1.Add(p[i],dp[i]-i);
		B2.Add(p[i],dp[i]+i);
	}
	cout<<dp[n]<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}

//qwq