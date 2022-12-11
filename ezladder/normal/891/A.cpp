#include <bits/stdc++.h>
			 
#define x first
#define y second
#define mp make_pair
#define pub push_back
#define all(a) a.begin(), a.end()
#define ll long long
#define db double
	
using namespace std;

int n;
int a[2222];

int main(){
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int val = a[0];
	for (int i = 0; i < n; i++) val = __gcd(val, a[i]);
	if (val > 1) cout << -1, exit(0);
	int ans = 0;
	for (int i = 0; i < n; i++) if (a[i] == 1) ans++;
	if (ans > 0){
		cout << n - ans;
		exit(0);
	}
	int need = n + 7;
	for (int i = 0; i < n; i++){
		if (a[i] == 1){
			need = 0;
			break;
		}
		int val = a[i];
		for (int j = i + 1; j < n; j++){
			val = __gcd(val, a[j]);
			if (val == 1){
				need = min(need, j - i);
				break;
			}
		}
	}
	cout << need + n - 1;
}