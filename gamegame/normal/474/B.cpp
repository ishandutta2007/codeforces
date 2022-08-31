#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	int q;cin >> q;
	while(q--){
		ll x;cin >> x;
		ll p=lower_bound(a+1,a+n+1,x)-a;
		cout << p << '\n';
	}
}