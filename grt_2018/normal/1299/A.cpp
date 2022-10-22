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

const int nax = 100*1000+10;
int n;
int a[nax],l[nax],r[nax];
int ans = -1,g = -1;

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		l[i] = l[i-1]|a[i];
	}
	for(int i=n; i>=1; i--) {
		r[i] = r[i+1]|a[i];
	}
	for(int i=1; i<=n; i++) {
		int o = l[i-1]|r[i+1];
		int w = a[i] - (a[i]&o);
		if(w>ans) {
			ans = w;
			g = i;
		}
	}
	cout<<a[g]<<" ";
	for(int i=1; i<=n; i++) {
		if(i==g) continue;
		cout<<a[i]<<" ";
	}
	
}