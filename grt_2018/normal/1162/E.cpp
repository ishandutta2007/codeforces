#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int n,cnt,m=100,t[51];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>t[i];
		m=min(m,t[i]);
	}
	for(int i=0; i<n;i++) {
		if(t[i]==m) {
			cnt++;
		}
	}
	if(cnt<=n/2) cout<<"Alice";
	else cout<<"Bob";
}