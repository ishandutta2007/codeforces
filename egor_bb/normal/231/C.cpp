#pragma comment (linker, "/STACK:10000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort

using namespace std;



ll n, a[100005], sum[100005], k;

ll gsum(ll a, ll b){
	return (sum[b] - sum[a - 1]);
}
ll max(ll a, ll b){
	if (a > b) return a;
	return b;
}
int main(){
	//ifstream cin ("in.txt");
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	ll ans = 0, p = 0;
	for (int i = 1; i <= n; i++){
		ll lft = 0, rgt = i;
		while (rgt - lft > 1){
			ll m = (rgt + lft) / 2;
			if (gsum(m, i) >= a[i] * (i - m + 1) - k){
				rgt = m;
			} else {
				lft = m;
			}
		}
		if (ans < i - rgt + 1){
			ans = i - rgt + 1;
			p = a[i];
		}
	}
	cout << ans << " " << p;
	return 0;
}