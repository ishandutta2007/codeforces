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

const int nax = 200*1000+10,INF=1e9;
int n,ans=INF,t;
int a[nax],last[nax];

int main() {_
	cin>>t;
	while(t--) {
	ans=INF;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) last[i]=-INF;
	for(int i=0; i<n; i++) {
		ans = min(ans,i-last[a[i]]+1);
		last[a[i]] = i;
	}
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
}
}