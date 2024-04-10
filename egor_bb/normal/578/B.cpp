#pragma comment (linker, "/STACK:1000000000")

#include <iostream>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
 
typedef long long ll;
typedef unsigned long long ull;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
const ll N = 100005;

#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair
#define pb push_back
#define sz(x) int(x.size())
#define problem "test"
 
using namespace std;

int a[200005], n, k, x;
ll p[200005], s[200005];

int main(){
//	freopen (problem".in", "r", stdin);
//	freopen (problem".out", "w", stdout);
	cin >> n >> k >> x;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++){
		p[i] = p[i - 1] | a[i];
	}
	for (int i = n; i >= 1; i--){
		s[i] = s[i + 1] | a[i];
	}
	ll ans = 0;
	for (int i =  1; i <= n; i++){
		ll t = a[i];
		for (int kk = 0; kk < k; kk++){
			t *= x;
		}
		t = (s[i + 1] | t | p[i - 1]);
		ans = max(ans, t);
	}
	cout << ans << '\n';
}