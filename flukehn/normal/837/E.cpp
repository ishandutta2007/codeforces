#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return b ? gcd(b, a % b) : a;
}
ll f(ll a, ll b) {
	if (!b) return b;
	ll g = gcd(a, b);
	a /= g, b /= g;
	ll ne = a, mn = b;
	for (ll i = 2; i * i <= a; i++)
		if (a % i == 0) {
			mn = min(mn, b % i);
			while (a % i == 0) a /= i;
		}
	if (a != 1) mn = min(mn, b % a);
	return mn + f(ne, b - mn); 
}
int main(){
	ll a, b;
	cin >> a >> b;
	cout << f(a, b) << endl;	
}