#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 100*1000+10;
int n;
int a[nax];
int cnt[2];
ll s;

int main() {_
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		s+=a[i];
		cnt[a[i]&1] = 1-cnt[a[i]&1];
	}
	bool ok=1;
	for(int i=0; i<n;i++) {
		if(a[i]>s-a[i]) ok=0;
	}
	if(ok==0||cnt[0]!=(n&1)||cnt[1]==1) {
		cout<<"NO";
	}
	else  {
		cout<<"YES";
	}
		
}