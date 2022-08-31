#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int solve(ll n,int m){
	if(m==0) return n;
	ll z=1;
	for(int i=1; i<=m ;i++) z=z*10+1;
	ll way1=(n/z)*(m+1)+solve(n%z,m-1);
	ll way2=(n/z+1)*(m+1)+solve(z-n%z,m-1);
	return min(way1,way2);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll n,m;
	cin >> n;
	m=0;
	ll z=1;
	while(z*10<=n){
		z*=10;
		m++;
	}
	int ans=solve(n,m+2);
	cout << ans << '\n';
}