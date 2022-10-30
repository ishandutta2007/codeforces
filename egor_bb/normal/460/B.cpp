#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cstddef>

#define ll long long
#define INFi 1000000009
#define INFl 1000000000000000009
#define mp make_pair
#define pb push_back
#define sort stable_sort

using namespace std;


ll a, b, c;

ll sum(ll a){
	ll ans = 0;
	while (a != 0){
		ans += a%10;
		a /= 10;
	}
	return ans;
}

ll calc(ll x){
	ll ans = 1;
	for (int i = 0; i	 < a; i++) ans *= x;
	ans *= b;
	ans += c;
	return ans;
}

int main(){
	cin >> a >> b >> c;
	ll r = 0, s[500];
	for (int i = 0; i < 100; i++){
		ll f = calc(i);
		if (i == sum(f) && f < 1e9 && f > 0){
			s[r] = f;
			r++;
		}
	}
	cout << r << '\n';
	for (int i = 0; i < r; i++) cout << s[i] << " ";
}