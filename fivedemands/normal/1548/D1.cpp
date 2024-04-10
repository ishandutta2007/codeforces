#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=6001;
int n;
ll x[N],y[N];
ll f[4][4];
ll C3(ll x){
	return x*(x-1)*(x-2)/6;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
		f[x[i]%4][y[i]%4]++;
	}
	ll fun=f[0][0]*f[0][2]*f[2][0]+f[0][0]*f[0][2]*f[2][2]+f[0][0]*f[2][2]*f[2][0]+f[2][2]*f[0][2]*f[2][0];
	cout << C3(n)-fun << endl;
}