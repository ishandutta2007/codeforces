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
int n,cnt;
ll ans;
int a[nax];
bool z;

int main() {_
	cin>>n;
	for(int i=0; i<n;i++) {
		cin>>a[i];
		if(a[i]==0) z = 1;
		if(a[i]>=0) ans+=(abs(1-a[i]));
		else {
			ans+=(abs(a[i]+1));
			cnt++;
		}
	}
	if(cnt%2==0) cout<<ans;
	else if(z) cout<<ans;
	else cout<<ans+2;
}