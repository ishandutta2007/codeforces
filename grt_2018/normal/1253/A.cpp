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
int t,n;
int a[nax], b[nax];


int main() {_
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n;i++) cin>>a[i];
		for(int i=1; i<=n; i++) {
			cin>>b[i]; a[i]-=b[i];
		}
		int wsk = 1;
		bool done=0,ok=1;
		while(wsk<=n) {
			if(a[wsk]==0) {
				wsk++;
			} else {
				if(a[wsk]>0) ok=0;
				if(done) ok=0;
				while(wsk+1<=n&&a[wsk+1]==a[wsk]) wsk++;
				done=1;
				wsk++;
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
			
	
	
}