#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 200005;

int n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int last = n;
		for (int i = n - 1; i; i--) {
			last = (i + last + 1) / 2;
		}	
		printf("%d\n", last);
		last = n;
		for (int i = n - 1; i; i--) {
			printf("%d %d\n", last, i); 
			last = (i + last + 1) / 2;
		}	
	}	
	return 0;
}