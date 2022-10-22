#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

#define int long long
mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const long long BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;
typedef long long ll;

vector <int> primes(int n){
	int div = 2;
	vector <int> res;
	while (div * div <= n){
		if (!(n % div)){
			n /= div;
			res.push_back(div);
		}
		else{
			++div;
		}
	}

	if (n != 1) res.push_back(n);
	return res;
}

int gcd(int a, int b){
	while (b){
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

signed main(){
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	vector <int> p = primes(x);

	int ans = 0;
	int g = gcd(x, y);
	int kx = x / g;
	int ky = y / g;
	while (y){
		int best = ky;
		for (int div : p){
			best = min(best, ky % div);
		}

		y -= best * g;
		ans += best;
		g = gcd(x, y);
		kx = x / g;
		ky = y / g;
		p = primes(kx);
	}

	cout << ans << '\n';
	return 0;
}