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

int t,n,k;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>k;
		vector<ll> a(n);
		vector<bool> done(64);
		for(int i=0; i<n; i++) cin>>a[i];
		bool ok = 1;
		for(auto &x:a) {
			ll cur = 1;
			int step = 0;
			while(cur*k<=x) {
				cur*=k;
				step++;
			}
			while(x>0) {
				if(done[step]) ok = 0;
				done[step] = 1;
				x-=cur;
				while(cur>x) {
					cur/=k;
					step--;
				}
			}
		}
		if(!ok) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
}