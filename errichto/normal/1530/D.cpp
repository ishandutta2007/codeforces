// I'm not using linux+geany today not to spoil anything from
//	the Harbour.Space round in two days.

#include <bits/stdc++.h>
using namespace std;

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> a(n + 1);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	vector<int> b(n + 1);
	vector<int> taken(n + 1); // reverse edges
	for(int i = 1; i <= n; ++i) {
		if(taken[a[i]] == 0) {
			// i -> a[i]
			b[i] = a[i];
			taken[a[i]] = i;
		}
	}
	vector<int> not_taken;
	for(int i = 1; i <= n; ++i) {
		if(taken[i] == 0) {
			not_taken.push_back(i);
		}
	}
	
	for(int i = 1; i <= n; ++i) {
		if(b[i] == 0) {
			// earlier, couldn't satisfy the preferences
			assert(!not_taken.empty());
			if(not_taken.back() == i) {
				swap(not_taken.back(), not_taken[0]);
			}
			if(not_taken.back() == i) {
				assert((int) not_taken.size() == 1);
				int j = taken[a[i]];
				b[j] = i;
				b[i] = a[i];
				//at the end, i -> i
				//find y such that y -> a[i]
				//y -> i
				//i -> a[i]
				not_taken.pop_back();
			}
			else {
				b[i] = not_taken.back();
				taken[not_taken.back()] = i;
				not_taken.pop_back();
			}
		}
	}
	
	int count = 0;
	for(int i = 1; i <= n; ++i) {
		count += (a[i] == b[i]);
	}
	printf("%d\n", count);
	for(int i = 1; i <= n; ++i) {
		printf("%d ", b[i]);
	}
	puts("");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}