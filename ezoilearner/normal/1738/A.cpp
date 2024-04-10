#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rof(i,a,b) for(int i=(a);i>=(b);--i)
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
constexpr int N=2e5+5;
int T,a[N];
vector<int>v[2];
inline void solve(){
	int n,x; ll ans=0;
	v[0].clear(),v[1].clear();
	cin>>n;
	For(i,1,n)cin>>a[i];
	For(i,1,n)cin>>x,ans+=x,v[a[i]].eb(x);
	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());
	reverse(v[0].begin(),v[0].end());
	reverse(v[1].begin(),v[1].end());
	if(v[0].size()==v[1].size()){
		auto p=min_element(v[0].begin(),v[0].end());
		auto q=min_element(v[1].begin(),v[1].end());
		cout<<ans*2-min(*p,*q)<<endl;return;
	}
	int k=min((int)v[0].size(),(int)v[1].size());
	For(i,0,k-1)ans+=v[0][i]+v[1][i];
	cout<<ans<<endl;
}
int main(){
	cin>>T;
	while(T--)solve();
	return 0;
}