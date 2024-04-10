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

const int nax = 400*1000+10;
int n;
int a[nax],t[nax];
int ans;

int gr(int x) {
	ll w = 0;
	int wsk = n;
	for(int i=1; i<=n; i++) {
		wsk = max(wsk,i+1);
		while(wsk-1>i&&t[wsk-1]+t[i]>=x) wsk--;
		if(wsk>i&&t[wsk]+t[i]>=x) {
			w+=(n-wsk+1);
		}
	}
	//cout<<x<<" "<<w<<"\n";
	return w;
}

int main() {_
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int bit = 1; bit<27; bit++) {
		ll w = 0;
		for(int i=1; i<=n; i++) {
			t[i] = a[i]%((1<<bit));
		}
		sort(t+1,t+n+1);
		w = gr((1<<(bit-1))) - gr((1<<(bit))) + gr((1<<bit)+(1<<(bit-1)));
		//cout<<w<<"\n";
		if(w&1) ans+=(1<<(bit-1));
	}
	cout<<ans;
}