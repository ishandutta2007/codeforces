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

const int mod = 998244353;
int n,m,l,r;

int fast_pow(int a, ll b) {
	int w = 1;
	while(b>0) {
		if(b&1) w = ((ll)w*a)%mod;
		b/=2;
		a = ((ll)a*a)%mod;
	}
	return w;
}

int main() {_
	cin>>n>>m>>l>>r;
	if((n&1)&&(m&1)) {
		int ans = fast_pow(r-l+1,(ll)n*m);
		cout<<ans;
		return 0;
	}
	int w1 = fast_pow(r-l+1,(ll)n*m);
	int a = (r-l+1)/2, b = (r-l+1)-a;
	int w2 = fast_pow(a-b,(ll)n*m);
	w1 = (w1+w2)%mod;
	w1 = ((ll)w1*fast_pow(2,mod-2))%mod;
	cout<<w1;
	
}