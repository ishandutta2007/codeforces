#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,cnt[30];
void Solve(){
	memset(cnt,0,sizeof(cnt));
	cin>>n>>m;
	for(int i=1,x;i<=n;++i){
		cin>>x;
		for(int j=0;j<m;++j){
			cnt[j]+=x>>j&1?1:-1;
		}
	}
	int ans=0;
	for(int j=0;j<m;++j){
		if(cnt[j]>0)ans|=1<<j;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}