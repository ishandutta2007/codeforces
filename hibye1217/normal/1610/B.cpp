#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// #define DEBUG

int n;
int arr[200020];

bool f(int val){
	int p1 = 1, p2 = n;
	while (p1 <= p2){
		while (p1 <= n){
			if (arr[p1] == val){ p1 += 1; }
			else{ break; }
		}
		while (1 <= p2){
			if (arr[p2] == val){ p2 -= 1; }
			else{ break; }
		}
		if (p1 > p2){ break; }
		if (arr[p1] != arr[p2]){ return 0; }
		p1 += 1; p2 -= 1;
	}
	return 1;
}

void Main(){
	int t; cin >> t;
	while (t--){
		cin >> n;
		for (int i = 1; i <= n; i++){ cin >> arr[i]; }
		int p1 = -1, p2 = -1;
		for (int i1 = 1; i1 <= n; i1++){
			int i2 = n+1 - i1;
			if (arr[i1] != arr[i2]){ p1 = i1; p2 = i2; break; }
		}
		if (p1 == -1){ cout << "YES" << endl; }
		else{
			cout << ( f(arr[p1]) || f(arr[p2]) ? "YES" : "NO" ) << endl;
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