#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10;
const ll INF=1e18+1;
int n,k;
int a[nax];
ll pref[nax],suf[nax];
ll ans=INF;

int main() {_
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		pref[i] = pref[i-1] + a[i];
	}
	for(int i=n; i>=1; i--) {
		suf[i] = suf[i+1] + a[i];
	}
	for(int i=1; i<=n; i++) {
		int up_to = i;
		while(up_to+1<=n&&a[i]==a[up_to+1]) {
			up_to++;
		}
		int cnt = up_to - i + 1;
		ll equal_smaller = (ll)(a[i]-1)*(i-1) - pref[i-1];
		ll equal_bigger = suf[up_to+1] - (ll)(a[i]+1)*(n-up_to);
		//cout<<a[i]<<" "<<cnt<<" "<<equal_smaller<<" "<<equal_bigger<<"\n";
		if(cnt>=k) ans = 0;
		else {
			if(k-cnt<=i-1) {
				ans = min(ans,equal_smaller+(k-cnt));
			} 
			if(k-cnt<=n-up_to) {
				ans = min(ans,equal_bigger+(k-cnt));
			}
			ans = min(ans,equal_smaller+equal_bigger+(k-cnt));
		}
		i = up_to;
	}
	cout<<ans;
	
}