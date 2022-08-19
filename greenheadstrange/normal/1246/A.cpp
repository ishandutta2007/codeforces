#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int cal(int a) {
	if (a < 0) return -2e9;
	if (a == 0) return 0;
	return (a % 2) + cal(a / 2);
}
int main() {
	int mxs = 4e5;
	int n, p;
	cin >> n >> p;
	for (int i = 0; i <= mxs; i++) {
		ll ed = n - 1ll * i * p;
		if (ed < 0) continue;
		if (ed < i) continue;
		if (cal(ed) > i) continue;
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}