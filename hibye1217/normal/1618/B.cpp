#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

// #define DEBUG

string arr[120];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n-2; i++){
			cin >> arr[i];
		}
		bool flg = 1;
		cout << arr[1];
		for (int i = 2; i <= n-2; i++){
			if (arr[i-1][1] == arr[i][0]){ cout << arr[i][1]; }
			else{ cout << arr[i][0] << arr[i][1]; flg = 0; }
		}
		if (flg){ cout << 'a'; }
		cout << endl;
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