//Author: Heltion
//Date: 2019-04-24
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
LL gcd(LL a, LL b){
	return b ? gcd(b, a % b) : a;
}
LL lcm(LL a, LL b){
	return a * b / gcd(a, b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//gcd(a + k, b + k) == gcd(a - b, a + k);
	LL a, b;
	cin >> a >> b;
	if(a < b) swap(a, b);
	LL x = abs(a - b), ans = lcm(a, b), ansk = 0;
	for(LL i = 1, k; i * i <= x; i += 1) if(x % i == 0){
		k = i - a % i;
		if(lcm(a + k, b + k) < ans){
			ans = lcm(a + k, b + k);
			ansk = k;
		}
		k = x / i - a % (x / i);
		if(lcm(a + k, b + k) < ans){
			ans = lcm(a + k, b + k);
			ansk = k;
		}
	}
	if(a > b){
		
	} 
	cout << ansk;
	return 0;
}