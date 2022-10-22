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
int n,m;
int a[nax];
ll p[nax];
ll odp[nax];

int main() {_
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) p[i]=p[i-1]+a[i];
	for(int l=1; l<=m; l++) {
		ll ans = p[l]-p[0];
		ll sum = ans;
		odp[l] = ans;
		for(int i=m+l; i<=n; i+=m) {
			ans+=sum+p[i]-p[i-m];
			sum+=p[i]-p[i-m];
			odp[i] = ans;
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<odp[i]<<" ";
	}
		
		
	
}