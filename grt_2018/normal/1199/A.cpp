#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax = 100*1000+10;
int t[nax];
int n,x,y;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>x>>y;
	for(int i=0; i<n;i++) cin>>t[i];
	for(int i=0; i<n;i++) {
		int m = 1000*1000*1000;
		for(int j=max(0,i-x); j<=min(n-1,i+y); j++) {
			m=min(m,t[j]);
		}
		if(m==t[i]) {
			cout<<i+1;
			return 0;
		}
	}
}