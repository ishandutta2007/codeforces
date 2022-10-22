#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;

int arr[60];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int flg1 = 3, flg2 = 3;
		for (int i = 1; i <= n; i++){
			if (i & 1){
				if (arr[i] & 1){ flg1 &= 1; }
				else{ flg1 &= 2; }
			}
			else{
				if (arr[i] & 1){ flg2 &= 1; }
				else{ flg2 &= 2; }
			}
		}
		if (flg1 && flg2){ cout << "Yes" << endl; } else{ cout << "No" << endl; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}