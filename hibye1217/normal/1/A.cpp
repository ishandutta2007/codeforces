#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using ll = long long;
using namespace std;

void solve(){
	ll n, m, a;
	cin >> n >> m >> a;
	cout << ((n+a-1) / a) * ((m+a-1) / a); // ceil(N/A) * ceil(M/A)
}

int main(){
	FastIO;
	solve();
}