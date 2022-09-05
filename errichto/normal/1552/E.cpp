#include <bits/stdc++.h>
using namespace std;
 
void test_case() {
    long long h = 0;
    for(int i = 1 ;i < 4000; ++i) {
        for(int j = 1; j < 2400; ++j) {
            h += __gcd(i, j);
        }
    }
    cerr << h << endl;
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> c(n * k);
	for(int i = 0; i < n * k; ++i) {
		scanf("%d", &c[i]);
	}
	int limit = (n + k - 2) / (k - 1);
	vector<int> prv(max(n, k) + 1, -1);
	vector<int> cnt(n * k);
	vector<pair<int,int>> done(max(n, k) + 1, make_pair(-1, -1));
	for(int i = 0; i < n * k; ++i) {
		// cerr << i << " " << c[i] << " " << prv.size() << endl;
		if(prv[c[i]] != -1
				&& done[c[i]].first == -1) {
			int L = prv[c[i]];
			int R = i;;
			bool ok = true;
			for(int j = L; j <= R; ++j) {
				if(cnt[j] == limit) {
					ok = false;
				}
			}
			if(ok) {
				done[c[i]] = {L + 1, R + 1};
				for(int j = L; j <= R; ++j) {
					cnt[j]++;
				}
			}
		}
		prv[c[i]] = i;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%d %d\n", done[i].first, done[i].second);
	}
}
 
int main() {
	// int T;
	// scanf("%d", &T);
	// while(T--) {
		test_case();
	// }
}