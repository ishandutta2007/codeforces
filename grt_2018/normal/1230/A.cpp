#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int a[4],s;

int main() {_
	bool ok = 0;
	cin>>a[0]>>a[1]>>a[2]>>a[3];
	s=a[0]+a[1]+a[2]+a[3];
	for(int i=0; i<4; i++) {
		for(int j=i+1; j<4; j++) {
			if(a[i]+a[j]==s - a[i] - a[j]) ok=1;
		}
	}
	for(int i=0; i<4; i++) if(2*a[i]==s) ok=1;
	if(ok) cout<<"YES";
	else cout<<"NO";
}