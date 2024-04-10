#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ld = long double;

int arr[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int dis = arr[n] - arr[1];
		if (n-1 <= dis && dis <= n+1){ cout << "Yes" << endl; } else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}