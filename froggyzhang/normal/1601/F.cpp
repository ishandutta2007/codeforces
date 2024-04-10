#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int B=1e6;
const int mod1=998244353;
const int mod2=1e9+7;
ll n,cnt;
vector<int> v[10];
int sum[10],ans,tot;
inline int calc(ll x){
	return (x%mod1+mod1)%mod1;	
}
void dfs1(int dep,int num){
	++cnt;
	v[dep].push_back(calc(cnt-num));
	if(dep==6)return;
	for(int i=0;i<=9;++i){
		dfs1(dep+1,num*10+i);
	}
}
void dfs2(int dep,ll num){
	if(num>n)return;
	if(dep>=1){
		if(num*B>n/10&&(num+1)*B-1<=n){
			int tmp=1;
			for(int i=0;i<=6;++i,tmp*=10){
				int w=calc(cnt-tmp*num);
				int pos=lower_bound(v[i].begin(),v[i].end(),mod1-w)-v[i].begin();
				ans=(ans+1LL*w*v[i].size()+sum[i]-1LL*mod1*((int)v[i].size()-pos))%mod2;
			}
			cnt+=tot;
			return;
		}
		++cnt;
		ans=(ans+calc(cnt-num))%mod2;
	}
	for(int i=!dep;i<=9;++i){
		dfs2(dep+1,num*10+i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	dfs1(0,0);
	for(int i=0;i<=6;++i){
		sort(v[i].begin(),v[i].end());
		sum[i]=accumulate(v[i].begin(),v[i].end(),0LL)%mod2;
	}
	tot=cnt;
	cnt=0;
	dfs2(0,0);
	cout<<(ans+mod2)%mod2<<'\n';
	return 0;
}