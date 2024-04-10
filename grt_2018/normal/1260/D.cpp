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
int n,m,k,t;
int a[nax];
vector<pi> trap[nax];

bool check(int x) {
	int wsk = 1,tot = 1;
	while(wsk<=n) {
		int z = wsk-1,l=wsk;
		for(auto it:trap[wsk]) {
			if(it.ST>x) z=max(z,it.ND);
		}
		while(wsk<z) {
			wsk++;
			for(auto it:trap[wsk]) {
				if(it.ST>x) z=max(z,it.ND);
			}
		}
		if(z==l-1) tot++;
		l = z-l+1;
		tot+=3*l;
		//cout<<x<<" : "<<wsk<<" "<<l<<"\n";
		wsk++;
	}
	//cout<<x<<" "<<tot<<"\n";
	return tot<=t;
}
			
			

int main() {_
	cin>>m>>n>>k>>t;
	for(int i=1; i<=m; i++) cin>>a[i];
	for(int x,y,z,i=1; i<=k; i++) {
		cin>>x>>y>>z;
		trap[x].emplace_back(z,y);
	}
	sort(a+1,a+m+1);
	reverse(a+1,a+m+1);
	for(int i=1; i<=n; i++) {
		sort(trap[i].begin(),trap[i].end());
		reverse(trap[i].begin(),trap[i].end());
	}
	int l=1, r=m, mid;
	while(l<=r) {
		mid=(l+r)/2;
		if(check(a[mid])) l = mid+1;
		else r = mid-1;
	}
	cout<<l-1;
}