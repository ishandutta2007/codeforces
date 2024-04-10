//I'm not using linux+geany today not to spoil anything from
//	the Harbour.Space round in two days.

#include <bits/stdc++.h>
using namespace std;

//my: (10, 15, 20, 25, 27, 30, 100, 100)
//      ^   ^

//he: (30, 50, 60, 65, 70, 80)
//      ^

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n);
	for(int& x : a) {
		scanf("%d", &x);
	}
	for(int& x : b) {
		scanf("%d", &x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int skipped = n / 4;
	int b_last_skipped = skipped - 1;
	int A = 0, B = 0;
	for(int i = skipped; i < n; ++i) {
		A += a[i];
		B += b[i];
	}
	int added = 0;
	while(A < B) {
		added++;
		A += 100;
		if((n + added) % 4 == 0) {
			int i = (n + added) / 4 - 1;
			if(i < n) {
				A -= a[i];
			}
			else {
				assert(false);
			}
		}
		else {
			int i = (n + added) / 4 - added;
			if(i >= 0) {
				B += b[i];
			}
		}
	}
	printf("%d\n", added);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}