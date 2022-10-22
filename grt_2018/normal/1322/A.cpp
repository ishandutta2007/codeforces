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

const int nax = 1000*1000+10;
int n;
string s;
int p[nax];
int ans = 0;

int main() {_
	cin>>n>>s;
	for(int i=1; i<=n; i++) {
		p[i] = p[i-1]+(s[i-1]=='('?1:-1);
	}
	if(p[n]!=0) {
		cout<<"-1";
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(p[i-1]==0&&p[i]<0) ans++;
		if(p[i]<0) ans++;
	}
	cout<<ans;
}