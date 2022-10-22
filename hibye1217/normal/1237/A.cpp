#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define fr first
#define sc second
using pi2 = pair<int, int>;

pi2 arr[14000];
int ans[14000];

void Main(){
	int n; cin >> n;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (abs(x) % 2 == 0){ arr[i] = {x/2, x/2}; }
		else{
			if (x >= 0){ arr[i] = {x/2, x/2+1}; }
			else{ arr[i] = {x/2-1, x/2}; }
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++){ sum += arr[i].fr; }
	for (int i = 1; i <= n; i++){
		if (sum < 0){
			sum += arr[i].sc - arr[i].fr;
			ans[i] = arr[i].sc;
		}
		else{
			ans[i] = arr[i].fr;
		}
	}
	for (int i = 1; i <= n; i++){ cout << ans[i] << endl; }
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