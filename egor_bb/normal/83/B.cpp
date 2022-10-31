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



ll n, a[100005], k, b[100005], g = 0;

/*ll gsum(ll a, ll b){
	return (sum[b] - sum[a - 1]);
}*/

ll max(ll a, ll b){
	if (a > b) return a;
	return b;
}
int main(){
	//ifstream cin ("in.txt");
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
		g += a[i];
	}
	if (g < k){
		cout << -1;
		return 0;
	}
	if (g == k){
		return 0;
	}
	sort (b + 1, b + n + 1);
	ll sum = 0, now = 1, gone = 0;
	while (sum + (n - gone) * (b[now] - b[now - 1]) <= k){
		sum += (n - gone) * (b[now] - b[now - 1]);
		ll t = now;
		now++;
		while (now <= n && b[now] == b[now - 1]) now++;
		gone += now - t;
	}
	ll delta = (k - sum) % (n - gone);
	ll start = 0, got = 0;
	//cout << sum << " " << delta << " " << b[now] << '\n';
	while (got != delta){
		start++;
		if (a[start] >= b[now]) got++;
	}
	if (k > sum + (n - gone) * (b[now] - b[now - 1] - 1)){
		ll d = k - sum - (n - gone) * (b[now] - b[now - 1] - 1);
		ll e = 1, gt = 0;
		while (gt != d){
			if (a[e] > b[now]){
				gt++;
			} else if (a[e] == b[now]){
				gt++;
				a[e] = 0;
			}
			e++;
		}
	}
	for (int i = start + 1; i <= n; i++){
		if (a[i] >= b[now]) cout << i << " ";
	}
	for (int i = 1; i <= start; i++){
		if (a[i] >= b[now]) cout << i << " ";
	}
	return 0;
}