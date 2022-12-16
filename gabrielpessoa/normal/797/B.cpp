#include <bits/stdc++.h>
using namespace std;

int arr[100005];
int main() {
	int n, sum = 0, dum, q = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &dum);
		if(dum > 0 && dum % 2 == 0) {
			sum += dum;
		} else if(dum % 2) {
			arr[q++] = dum;
		}
	}
	sort(arr, arr+q);
	sum += arr[q-1];
	for(int i = q-2; i > 0; i -= 2) {
		if(arr[i] + arr[i-1] > 0) sum += arr[i] + arr[i-1];
		else break;
	}
	printf("%d", sum);
	return 0;
}