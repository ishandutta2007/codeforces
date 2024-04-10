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
int t,n,m;

int main() {_
	cin>>t;
	while(t--) {
		cin>>n;
		int cntp0=0,cntp1=0,cntq0=0,cntq1=0;
		for(int x,i=0; i<n;i++) {
			cin>>x;
			if(x%2) cntp1++;
			else cntp0++;
		}
		cin>>m;
		for(int x,i=0; i<m; i++) {
			cin>>x;
			if(x%2) cntq1++;
			else cntq0++;
		}
		cout<<(ll)cntp0*cntq0+(ll)cntp1*cntq1<<"\n";
	}
	
}