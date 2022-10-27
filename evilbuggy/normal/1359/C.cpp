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

	int t;
	cin>>t;
	while(t--){
		ll h, c, t;
		cin>>h>>c>>t;
		ld diff = abs(ld(h + c)/2 - t);
		int ans = 2;
		int lo = 1, hi = 1e6;
		while(lo < hi){
			int mi = lo + (hi - lo + 1)/2;
			ld tmp = ld(mi*h + (mi - 1)*c)/ld(2*mi - 1);
			if(tmp >= t)lo = mi;
			else hi = mi - 1;
		}
		{
			ld tmp = ld(lo*h + (lo - 1)*c)/ld(2*lo - 1);
			if(abs(tmp - t) < diff){
				diff = abs(tmp - t);
				ans = 2*lo - 1;
			}
		}
		{
			ld tmp = ld(lo*h + h + lo*c)/ld(2*lo + 1);
			if(abs(tmp - t) < diff){
				diff = abs(tmp - t);
				ans = 2*lo + 1;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}