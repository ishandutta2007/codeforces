#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,dx,dy;
int m;
ll b[1000001];
int gx[1000001],gy[1000001];
int f(int x,int y){
	return ((dy*x-dx*y)%n+n)%n;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m >> dx >> dy;
	ll mx=0;
	for(int i=1; i<=m ;i++){
		ll x,y;cin >> x >> y;
		int h=f(x,y);
		b[h]++;
		gx[h]=x;gy[h]=y;
		mx=max(mx,b[h]);
	}
	for(int i=0; i<n ;i++){
		if(b[i]==mx){
			cout << gx[i] << ' ' << gy[i] << '\n';
			return 0;
		}
	}
}