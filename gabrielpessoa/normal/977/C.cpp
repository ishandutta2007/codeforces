#include<bits/stdc++.h>
using namespace std;

const int SIZE = 2e5+5;
int arr[SIZE];

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i<= n; i++) {
		cin >> arr[i];
	}
	arr[0] = 1;
	sort(arr, arr + n + 1);
	arr[n+1] = 0x3f3f3f3f;
	if(arr[k] == arr[k+1]) cout << -1 << '\n';
	else cout << arr[k] << '\n';
	return 0;
}