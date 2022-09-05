#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
long long len[nax], allow[nax];
vector<long long> w;
long long ans = 0;
const int magic = 100 * 1000;
int main() {
	int n;
	long long R;
	scanf("%d%lld", &n, &R);
	for(int i = 0; i < n; ++i) scanf("%lld", &len[i]);
	for(int i = 0; i < n; ++i) scanf("%lld", &allow[i]);
	for(int i = 0; i < n; ++i) if(len[i] > allow[i]) {
		puts("-1");
		return 0;
	}
	long long already = 0, fast = 0;
	for(int i = 0; i < n; ++i) {
		if(i) already += len[i-1];
		if(fast >= len[i]) {
			fast -= len[i];
			continue;
		}
		if(fast + 2 * (len[i] - fast) <= allow[i]) {
			fast = 0;
			continue;
		}
		long long x = fast + 2 * (len[i] - fast) - allow[i];
		assert(x > 0);
		ans += x / R;
		for(long long j = 0; j < x / R && (int) w.size() < magic; ++j)
			w.push_back(already + fast + j * R);
		if(x % R) {
			++ans;
			if((int) w.size() < magic)
				w.push_back(already + len[i] - x % R);
		}
		fast = R - x % R;
		if(fast == R) fast = 0;
	}
	printf("%lld\n", ans);
	long long move = 0;
	if(ans <= magic) {
		for(long long x : w) {
			printf("%lld ", 2 * x - move);
			move += R;
		}
		puts("");
	}
	
}