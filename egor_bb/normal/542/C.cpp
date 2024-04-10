#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;



ll n, a[205], b[205], c[205][205], d[205], t[205];
ll step = 1;

ll gcd(ll a, ll b){
	if (!a || !b) return a + b;
	return gcd(b, a % b);
}

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = i;
		t[i] = i;
		c[i][0] = i;
	}
	for (int i = 1; i < 202; i++){
		for (int j = 1; j <= n; j++){
			c[j][i] = a[c[j][i - 1]];
		}
	}
	for (int i = 1; i <= n; i++){
		vector <int> used;
		used.assign(n + 1, 0);
		ll cnt = 0;
		int j;
		for (j = i; !used[j]; j = a[j]){
			used[j] = 1;
			cnt++;
		}
		if (j == i) step = step * cnt  / gcd(step, cnt);
	}
	
	stack <int> deg;
	ll st = step;
	while (st){
		deg.push(st & 1);
		st >>= 1;
	}
	while (!deg.empty()){
		for (int i = 1; i <= n ;i++){
			d[i] = b[b[i]];
		}
		for (int i = 1; i <= n; i++) b[i] = d[i];
		if (deg.top()){
			for (int i = 1; i <= n; i++){
				b[i] = a[b[i]];
			}
		}
		deg.pop();
	}
	for (ll k = step; k < INFll; k += step){
		for (int i = 1; i <= n; i++){
			t[i] = b[t[i]];
		}
		bool flag = true;
		for (int i = 1; i <= n; i++){
			if (t[i] != t[t[i]]){
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << k << '\n';
				return 0;
		}
	}
	assert(1 == 2);
}