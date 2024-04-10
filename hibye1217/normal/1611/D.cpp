#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// #define DEBUG

int par[200020];
int arr[200020], inv[200020];
int dis[200020];
bool chk[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> par[i]; }
		for (int i = 1; i <= n; i++){
			cin >> arr[i];
			inv[ arr[i] ] = i;
		}
		for (int i = 1; i <= n; i++){
			int v = arr[i]; chk[v] = 1;
			if (!chk[ par[v] ]){ cout << -1; goto next; }
			dis[v] = i-1;
		}
		for (int i = 1; i <= n; i++){
			cout << (dis[i] - dis[ par[i] ]) << ' ';
		}
		next: cout << endl;
		for (int i = 1; i <= n; i++){
			par[i] = arr[i] = inv[i] = dis[i] = chk[i] = 0;
		}
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}