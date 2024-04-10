#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, d, m;
	cin>>n>>d>>m;
	vector<ll> a, b;
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		if(x <= m)a.emplace_back(x);
		else b.emplace_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	for(int i = 1; i < a.size(); i++){
		a[i] += a[i - 1];
	}
	int sza = a.size();
	int szb = b.size();
	ll ans = 0;
	if(sza)ans = a.back();
	ll sum = 0;
	for(int i = 1; i <= szb; i++){
		if((i - 1)*d + i > n)break;
		sum += b[i - 1];
		ll val = sum;
		if(szb - i >= (i - 1)*d){
			if(sza)val += a.back();
		}else{
			int rem = (i - 1)*d - szb + i;
			if(rem < sza)val += a.back() - a[rem - 1];
		}
		ans = max(ans, val);
	}
	cout<<ans;

	return 0;
}