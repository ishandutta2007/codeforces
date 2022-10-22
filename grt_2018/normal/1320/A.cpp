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
int n;
pi t[nax];
ll ans;

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>t[i].ND;
		t[i].ST = t[i].ND-i;
	}
	sort(t+1,t+n+1);
	ll w = t[1].ND;
	for(int i=2; i<=n; i++) {
		if(t[i].ST!=t[i-1].ST) {
			ans = max(ans,w);
			w = 0;
		}
		w+=t[i].ND;
	}
	ans = max(ans,w);
	cout<<ans;
		
	
}