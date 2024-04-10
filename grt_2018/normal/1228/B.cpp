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

const int nax = 1000+10,mod=1e9+7;
int w,h;
int r[nax],c[nax];
int t[nax][nax];

int main() {_
	cin>>h>>w;
	bool ok=1;
	for(int i=1; i<=h; i++) {
		cin>>r[i];
		for(int j=1; j<=r[i]; j++) {
			if(t[i][j]==2) ok=0;
			t[i][j] = 1;
		}
		if(r[i]<w&&t[i][r[i]+1]==1) ok=0;
		t[i][r[i]+1] = 2;
	}
	for(int i=1; i<=w; i++) {
		cin>>c[i];
		for(int j=1; j<=c[i]; j++) {
			if(t[j][i]==2) ok=0;
			t[j][i] = 1;
		}
		if(c[i]<h&&t[c[i]+1][i]==1) ok=0;
		t[c[i]+1][i] = 2;
	}
	if(!ok) {
		cout<<"0";
		return 0;
	}
	int ans=1;
	for(int i=1; i<=h; i++) {
		for(int j=1; j<=w; j++) {
			if(t[i][j]==0) ans=(ans*2)%mod;
		}
	}
	cout<<ans;
}