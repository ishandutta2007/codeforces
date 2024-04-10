#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		set<int> s{INT_MIN, INT_MAX};
		bool ok = true;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			auto it = s.insert(a[i]).first;
			if(i != 0 && a[i] != a[i-1] && *prev(it) != a[i-1] && *next(it) != a[i-1]) {
				ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
}



// 6 2 10 1 11







// 6 2


// 6 2 -INF _ _ _        

// lemma: smallest L/2 numbers dont matter



// -INF 2 6 X X


// _ _ 1 3