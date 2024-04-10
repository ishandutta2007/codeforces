#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 2000+10;
int n,a[2*nax],id;
int cnt[nax];
map<int,int>sc;
int ans;

int main() {_
	cin>>n;
	for(int i=1; i<=n;i++) {
		cin>>a[i]; sc[a[i]];
	}
	for(auto &it: sc) it.ND = ++id;
	for(int i=1; i<=n;i++) a[i] = sc[a[i]];
	a[0] = id+1; a[n+1] = id+2;
	for(int i=0; i<=n;i++) {
		cnt[a[i]]++;
		if(cnt[a[i]]==2) break;
		int x = n+1;
		while(x>i&&cnt[a[x]]==0) {
			cnt[a[x]]++;
			x--;
		}
		ans = max(ans,i+(n-x));
		for(int j=x+1; j<=n+1; j++) cnt[a[j]]--;
	}
	cout<<n-ans;
}