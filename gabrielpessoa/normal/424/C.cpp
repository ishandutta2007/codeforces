#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1E6 + 5;
typedef long long ll;
typedef vector<int> vi;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

ll arr[SIZE];

int main() {
	int n, q = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		q ^= x;
		arr[i] += (n-i) % 2;
		arr[i-1] -= (n-i) % 2;
		//printf("%d: %d\n", i, (n-i) % 2);
		if(((n - i)/i) % 2 == 0) {
			arr[(n-i) % i]++;
			//printf("%d: aumentou um\n", (n-i) % i);
		} else {
			arr[i-1]++;
			//printf("aumentou entre %d e %d\n", i -1, (n-i) % i);
			arr[(n-i) % i]--;
		}
	}
	ll count = 0;
	for(int i = n; i >= 1; i--) {
		count += arr[i];
		//printf("%d %lld\n", i, count);
		if(count % 2) {
			q ^= i;
		}
	}
	printf("%d\n", q);
}