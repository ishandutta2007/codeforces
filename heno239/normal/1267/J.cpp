#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)


void solve(){
	int n;
	cin>>n;
	vector<int> cnt(n+1);
	rep(i,n){
		int x;
		cin>>x;
		cnt[x]++;
	}
	vector<int> a;
	rep(i,n+1){
		if(cnt[i])a.push_back(cnt[i]);
	}
	sort(a.begin(),a.end());
	int ans = n;
	int mi= a[0], m = a.size();
	for(int i = 1;i<=mi+1;++i){
		bool ok = true;
		rep(j,m){
			int num = (a[j]+i-1)/i;
			if(num*(i-1)>a[j])ok=false;
		}
		if(ok){
			int ret = 0;
			rep(j,m){
				ret += (a[j]+i-1)/i;
			}
			ans = min(ans,ret);
		}
	}
	cout<<ans<<endl;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	rep(i,t){
		solve();
	}
}