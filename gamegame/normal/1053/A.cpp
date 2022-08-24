#include<iostream>
using namespace std;
typedef long long ll;
ll n,m,k;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	if(n*m*2%k!=0){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	if(k%2==0){
		k/=2;
		ll g=gcd(n,k);
		n/=g;
		m/=k/g;
		cout << "0 0\n" << n << ' ' << 0 << '\n' << 0 << ' ' << m << endl;
		return 0;
	}
	ll g=gcd(n,k);
	n/=g;
	m/=k/g;
	if(g>=2) n*=2;
	else m*=2;
	cout << "0 0\n" << n << ' ' << 0 << '\n' << 0 << ' ' << m << endl;
}