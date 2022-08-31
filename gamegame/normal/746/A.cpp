#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const int M=262144;
const ll mod=1e9+7;
const int mg=30;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(false);
	ll x,y,z;
	cin >> x >> y >> z;
	ll ans=min(x,y/2);
	ans=min(ans,z/4);
	cout << ans*7 << endl;
}