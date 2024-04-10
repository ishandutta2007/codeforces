#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int M=998244353,mod=1e9+7,B=1e6;
ll cnt,n;
int sum[10],ans=0;
vector<int> t[10];
void dfs1(int d,int val){
	if(d==7)return ;
	int x=((++cnt)-val+M)%M;
	t[d].push_back(x),sum[d]=(sum[d]+x)%mod;
	for(int i=0;i<10;i++)dfs1(d+1,val*10+i);
}
void dfs2(int d,ll val){
	if(val>n)return ;
	if(d&&val<=B&&(val+1)*B<=n&&10*val*B>n){
		int u=1;
		for(int i=0;i<7;i++){
			int w=(cnt-val*u%M+M)%M;
			int pos=lower_bound(t[i].begin(),t[i].end(),M-w)-t[i].begin();
			ans=(ans+1ll*w*t[i].size()+sum[i])%mod;
			ans=(ans-1ll*(t[i].size()-pos)*M%mod+mod)%mod;
			u*=10;
		}
		for(int i=0;i<7;i++)cnt+=t[i].size();
		return ;
	}
	if(d)cnt++,ans=(ans+(cnt-val%M+M)%M)%mod;
	for(int i=(d==0?1:0);i<10;i++)dfs2(d+1,val*10+i);
}
int main(){
	cin>>n,dfs1(0,0);
	for(int i=0;i<7;i++)sort(t[i].begin(),t[i].end());
	cnt=0,dfs2(0,0),cout<<ans;
}