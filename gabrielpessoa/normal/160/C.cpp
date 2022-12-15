#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

long long arr[SIZE];

int main() {
	long long n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	k--;
	sort(arr, arr+n);
	long long pos1 = k/n;
	long long primeiro = pos1;
	long long amount = 1;
	for(long long i = pos1 - 1; i >= 0; i--) {
		if(arr[i] == arr[pos1]) {
			amount++;
			primeiro = i;
		}
	}
	for(long long i = pos1 + 1; i < n; i++) {
		if(arr[i] == arr[pos1]) {
			amount++;
		}
	}
	long long pos2 = k - primeiro*n;
	pos2 = pos2 / amount;
	pos2 = pos2 % n;
	cout << arr[pos1] << " " << arr[pos2];
	return 0;
}