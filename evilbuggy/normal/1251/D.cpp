#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;
ll s, l[N], r[N];

bool isPossible(int n, ll med){
	vector<ll> tmp;
	int a = 0, b = 0;
	ll tot = 0;
	for(int i = 1; i <= n; i++){
		if(r[i] < med){
			a++;
			tot += l[i];
		}else if(l[i] > med){
			b++;
			tot += l[i];
		}else{
			tmp.push_back(l[i]);
		}
	}
	int k = (n-1)/2;
	if(a > k || b > k)return false;
	int req = k - a;
	sort(tmp.begin(), tmp.end());
	for(int i = 0; i < req; i++){
		tot += tmp[i];
	}
	tot += med*(k+1-b);
	if(tot > s)return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n>>s;
		vector<ll> arr;
		for(int i = 1; i <= n; i++){
			cin>>l[i]>>r[i];
			arr.push_back(l[i]);
		}
		sort(arr.begin(), arr.end());
		ll lo = arr[(n-1)/2];
		ll hi = s;
		while(lo < hi){
			ll mi = lo + (hi - lo + 1)/2;
			if(isPossible(n, mi)){
				lo = mi;
			}else{
				hi = mi - 1;
			}
		}
		cout<<lo<<'\n';
	}

	return 0;
}