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

void pass(){
	return;
}

#define int long long
#define x first
#define y second
#define prev _prev
#define rand() rand()<<15+rand()
typedef long long ll;
typedef unsigned long long ull;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 1e5 + 7;

int max_pow[50];

map <int, int> primes(int n){
	map <int, int> res;
	for (int div = 2; div * div <= n; ++div){
		while (!(n % div)){
			n /= div;
			res[div]++;
		}
	}
	
	if (n != 1) res[n]++;
	return res;
}

int get_pow(int n, int p){
	int res = 0;
	while (!(n % p)){
		n /= p;
		++res;
	}

	return res;
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	map <int, int> p = primes(k);
	for (int i = 0; i < n; ++i){
		cin >> a[i];

		int j = 0;
		for (pair <int, int> el : p){
			max_pow[j] = max(max_pow[j], get_pow(a[i], el.first));
			++j;
		}
	}

	int j = 0;
	for (pair <int, int> el : p){
		if (max_pow[j] < el.second){
			cout << "No\n";
			return 0;
		}
		
		++j;
	}

	cout << "Yes\n";;
	return 0;
}