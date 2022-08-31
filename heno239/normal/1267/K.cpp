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
	int ma = a[0], m = a.size();
	for(int i = 1;i<=ma;++i){
		bool ok = true;
		rep(j,m){
			if(a[j]%i>a[j]/i)ok=false;
		}
		if(ok){
			int ret = 0;
			rep(j,m){
			}
		}
	}
}

void solve(ll n){
	vector<int> a;
	ll c = 2;
	while(n){
		a.push_back(n%c);
		n/=c;
		c++;
	}
	sort(a.begin(),a.end());
	ll ans = 1;
	int m = a.size();
	int j = 0;
	int cnt = 0;
	rep(i,m){
		while(j<m && a[j]<=i+1)++j,++cnt;
		ans *= cnt;
		--cnt;
	}
	vector<int> d(m+1);
	rep(i,m)d[a[i]]++;
	rep(i,m+1){
		while(d[i]){
			ans/=d[i]--;
		}
	}
	if(a[0]==0){
		ll ans2 = 1;
		j=1;
		cnt = 0;
		rep(i,m-1){
			while(j<m && a[j]<=i+1)++j,++cnt;
			ans2 *= cnt;
			--cnt;
		}
		vector<int> d(m+1);
		rep(i,m-1)d[a[i+1]]++;
		rep(i,m+1){
			while(d[i]){
				ans2/=d[i]--;
			}
		}
		ans -= ans2;
	}
	
	cout<<ans-1<<endl;
}
int main(){
	int t;
	cin>>t;
	rep(i,t){
		ll l;cin>>l;
		solve(l);
	}
}