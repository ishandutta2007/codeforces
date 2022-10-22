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

const int nax = 12;
int cnt[nax];
int n,q;

int main() {_
	cin>>q;
	while(q--) {
		cin>>n;
		for(int i=0; i<=11; i++) cnt[i] = 0;
		for(int a,i=0; i<n; i++) {
			cin>>a;
			if(a>2048) continue;
			cnt[(int)log2(a)]++;
		}
		for(int i=0; i<11; i++) {
			cnt[i+1] += cnt[i]/2;
		}
		if(cnt[11]>0) cout<<"YES\n";
		else cout<<"NO\n";
	}
}