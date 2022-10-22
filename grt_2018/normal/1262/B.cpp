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
int q[nax];
int ans[nax];
bool used[nax];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>q[i];
			used[i] = 0;
		}
		int wsk = 1;
		ans[1] = q[1];
		used[q[1]]=1;
		bool ok=1;
		for(int i=2; i<=n; i++) {
			if(q[i]>q[i-1]) {
				if(used[q[i]]) {
					ok=0;
				}
				ans[i] = q[i];
				used[q[i]]=1;
			} else {
				while(used[wsk]&&wsk<q[i]) {
					wsk++;
				}
				if(used[wsk]) ok=0;
				ans[i]=wsk;
				used[wsk]=1;
			}
		}
		if(!ok) cout<<"-1\n";
		else {
			for(int i=1; i<=n; i++) {
				cout<<ans[i]<<" ";
			}
			cout<<"\n";
		}
	}
					
	
}