#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int SIZE = 2e5+5;

int arr[SIZE];
map<int, int> slv;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	int best = 0, ans = arr[0];
	for(int i = 0; i < n; i++) {
		int temp = slv[arr[i] - 1] + 1;
		slv[arr[i]] = max(slv[arr[i]], temp);
		if(temp > best) {
			best = temp;
			ans = arr[i] - temp + 1;
		}
	}
	cout << best << '\n';
	for(int i = 0; i < n; i++) {
		if(arr[i] == ans) {
			cout << i + 1 << ' ';
			ans++;
		}
	}
	cout << '\n';
	return 0;
}