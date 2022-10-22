#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;

int arr[200020], cnt[200020];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		bool flg = 0;
		for (int i = 1; i <= n; i++){
			int x; cin >> x; cnt[x] += 1;
			arr[i] = x;
			if (cnt[x] == 3 && !flg){ cout << x << endl; flg = 1; }
		}
		if (!flg){ cout << -1 << endl; }
		for (int i = 1; i <= n; i++){ cnt[ arr[i] ] = 0; }
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}