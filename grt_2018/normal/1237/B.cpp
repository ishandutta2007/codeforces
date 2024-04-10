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

const int nax = 100*1000+10,INF=1e9;
int n,ans;
int a[nax],b[nax];

int main() {_
	cin>>n;
	for(int x,i=1; i<=n; i++) {
		cin>>x;
		a[x] = i;
	}
	for(int i=1; i<=n; i++) cin>>b[i];
	int m = INF;
	for(int i=n; i>=1; i--) {
		if(a[b[i]]>m) ans++;
		m = min(m,a[b[i]]);
	}
	cout<<ans;
	
}