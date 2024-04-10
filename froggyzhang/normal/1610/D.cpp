#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=1e9+7;
int n,a[N],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	ans=1;
	for(int i=1;i<=n;++i){
		ans=(ans<<1)%mod;
	}
	ans=(ans+mod-1)%mod;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int T=1;T<=30;++T){
		int cnt[4]={1,0,0,0};
		for(int i=1;i<=n;++i){
			if(a[i]&1){
				continue;
			}
			int tmp[4]={cnt[0],cnt[1],cnt[2],cnt[3]};
			ans=(ans+mod-cnt[((2-a[i])%4+4)%4])%mod;
			for(int j=0;j<4;++j){
				cnt[(j+a[i])%4]=(cnt[(j+a[i])%4]+tmp[j])%mod;
			}
		}
		for(int i=1;i<=n;++i){
			if(a[i]%2==0)a[i]>>=1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}