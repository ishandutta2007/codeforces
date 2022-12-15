#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 505;
const double PI = 3.14159265359;

int arr[SIZE];

int main() {
	int n;
	long long k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if(k >= n - 1) {
		sort(arr, arr+n);
		printf("%d\n", arr[n-1]);
		return 0;
	}
	int curWin = 0;
	int curK = 0;
	while(curK < k) {
		if(arr[curWin] > arr[(curWin+1) % n]) {
			swap(arr[curWin], arr[(curWin+1)%n]);
			curK++;
		} else {			
			curK = 1;
		}
		curWin = (curWin+1)%n;
	}
	printf("%d\n", arr[curWin]);
	return 0;
}