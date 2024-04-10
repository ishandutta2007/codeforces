#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n; ll x;
	cin>>n>>x;
	vector<ll> d(n), val;
	for(auto &a : d){
		cin>>a;
	}
	for(int i = 0; i < n; i++){
		d.push_back(d[i]);
	}
	val.push_back(d[0]*(d[0] + 1)/2);
	for(int i = 1; i < d.size(); i++){
		val.push_back(d[i]*(d[i] + 1)/2 + val.back());
	}
	ll ans = 0;
	int r = -1;
	ll cur = 0;
	for(int i = 0; i < n; i++){
		if(d[i] >= x)ans = max(ans, d[i]*x - x*(x - 1)/2);
		if(r < i){
			cur = d[i];
			r = i;
		}
		while(cur + d[r + 1] <= x){
			cur += d[r + 1];
			r++;
		}
		if(cur > x)continue;
		ll tmp = val[r]; if(i)tmp -= val[i - 1];
		ll rem = x - cur;
		tmp += rem*(rem + 1)/2;
		ans = max(ans, tmp);
		cur -= d[i];
	}
	int l = 0;
	cur = 0;
	for(int i = 0; i < 2*n; i++){
		cur += d[i];
		while(l < i && cur > x){
			cur -= d[l];
			l++;
		}
		if(cur > x)continue;
		ll tmp = val[i]; if(l)tmp -= val[l - 1];
		ll rem = x - cur;
		if(l)tmp += d[l - 1]*rem - rem*(rem - 1)/2;
		ans = max(ans, tmp);
	}
	cout<<ans<<endl;


	return 0;
}