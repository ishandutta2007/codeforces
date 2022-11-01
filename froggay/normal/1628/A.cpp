#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,a[N],cnt[N],c[N];
void Solve(){
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<=n+1;++i)cnt[a[i]]=0;
	for(int i=n,j=0;i>=1;--i){
		++cnt[a[i]];
		while(cnt[j])++j;
		c[i]=j;
	}
	for(int i=0;i<=n+1;++i)cnt[a[i]]=0;
	vector<int> ans;
	for(int i=1;i<=n;++i){
		int zz=c[i];
		ans.push_back(zz);
		int pre=i;
		int k=0;
		while(true){
			++cnt[a[i]];
			while(cnt[k])++k;
			if(k==zz)break;
			++i;
		}
		for(int j=pre;j<=i;++j)cnt[a[j]]=0;
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans){
		cout<<x<<' ';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}