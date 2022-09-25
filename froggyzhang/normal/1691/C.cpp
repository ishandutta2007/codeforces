#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,k;
char s[N];
void Solve(){
	cin>>n>>k;
	cin>>(s+1);
	int mn=n+1,cnt=0,mx=0;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'){
			++cnt;
			mn=min(mn,i);
			mx=max(mx,i);
		}
	}
	if(!cnt){
		cout<<0<<'\n';
		return;
	}
	int ans=cnt*11;
	if(k>=n-mx){ans-=10;k-=n-mx;--cnt;}
	if(k>=mn-1&&cnt){ans-=1;}
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