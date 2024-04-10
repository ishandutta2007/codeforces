#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N];
map<int,int> mp;
bool dfs(ll x){
	if(mp[x]){--mp[x];return 1;}
	if(x==1)return 0;
	if(dfs(x>>1))return dfs((x+1)>>1);
	else return 0;
}
void Solve(){
	cin>>n;
	mp.clear();
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++mp[a[i]];
	}
	ll sum=accumulate(a+1,a+n+1,0LL);
	if(!dfs(sum)){
		cout<<"NO\n";
		return;
	}
	ll o=0;
	for(auto [x,y]:mp)o+=y;
	cout<<(o<=1?"YES\n":"NO\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}