#include<bits/stdc++.h>
#include<unordered_map>
#define re register
using namespace std;
#define int long long
int n,a[100002],ans[100002],s;
unordered_map <int,int> mp; 
signed main(){
	scanf("%lld",&n);
	for(re int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(re int i=30;i>0;--i){
		mp.clear();
		for(re int j=1;j<=n;++j){
			if(mp[a[j]>>i]==((a[j]&(1<<(i-1)))+1))continue;
			if(!mp[a[j]>>i])mp[a[j]>>i]=(a[j]&(1<<(i-1)))+1;
			else mp[a[j]>>i]=-1;
		}
		for(re int j=1;j<=n;++j){
			if(mp[a[j]>>i]==-1)ans[j]+=(1<<(i-1));
		}
	}
	s=1e18;
	for(re int i=1;i<=n;++i)if(ans[i]<s)s=ans[i];
	printf("%lld",s);
	}