#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int arr[SIZE];
char s[SIZE];

int main() {
	int n, k;
	scanf("%d %d %s", &n, &k, s);
	for(int i = 1; i <= n; i++) {
		arr[i] = arr[i-1];
		if(s[i-1] == '0') {
			arr[i]++;
		}
	}
	int l = 1, r = 100000;
	while(l < r - 1) {
		int m = (l+r)/2;
		bool achado = false;
		for(int i = 0; i < n; i++) {
			if(s[i] == '1') {
				continue;
			}
			int cows = 0;
			if(m > i) {
				cows += arr[i];
			} else {
				cows += arr[i] - arr[i-m];
			}
			if(m >= (n-i)) {
				cows += arr[n] - arr[i+1];
			} else {
				cows += arr[i+m+1] - arr[i+1];
			}
			if(cows >= k) {
				achado = true;
				break;
			}
		}
		if(achado) {
			r = m;
		} else {
			l = m;
		}
	}
	int m = l;	
	bool achado = false;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {
			continue;
		}
		int cows = 0;
		if(m > i) {
			cows += arr[i];
		} else {
			cows += arr[i] - arr[i-m];
		}
		if(m >= (n-i)) {
			cows += arr[n] - arr[i+1];
		} else {
			cows += arr[i+m+1] - arr[i+1];
		}
		if(cows >= k) {
			achado = true;
			break;
		}
	}
	if(achado) {
		printf("%d\n", l);
	} else {
		printf("%d\n", r);
	}
	return 0;
}