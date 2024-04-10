#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

int t,n;
string s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--) {
		cin>>n>>s;
		int p = n-10;
		bool ok=0;
		for(int i=0; i<p; i++) {
			if(s[i]=='8') {
				ok=1;
			}
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
}