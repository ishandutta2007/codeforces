#include <bits/stdc++.h>
using namespace std;

int arr[100005];
vector<int> vec[100005];

int main() {
	long long n, k, m, x, best = 0, pos, bestPos;
	cin >> n >> k >> m;
	for(int i = 0; i < n; i++) {
		cin >> x;
		vec[x % m].push_back(x);
		if(++arr[x % m] > best) {
			best = arr[x % m];
			bestPos = x % m;
		}
	}
	if(best >= k) {
		puts("Yes");
		for(int i = 0; i < k; i++) {
			if(i) {
				printf(" ");
			}
			printf("%d", vec[bestPos][i]);
		}
	} else {
		puts("No");
	}
	
}