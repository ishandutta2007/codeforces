#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int Read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >='0' && ch <='9'){x = x*10 + ch - '0'; ch = getchar();}
	return x*f; 
}

int T, n, a[15];

int main() {
	T = Read();
	while(T--) {
		n = Read();
		int cnt = 0;
		for(int i = 1; i <= 7; ++i) a[i + 7] = a[i] = Read(), cnt += a[i];
		if(cnt == 7) {
			printf("%d\n", n);
			continue;
		}
		int k = (n - 1)/cnt;
		int ans = k*7;
		n -= k*cnt;
		int res = 1000000000;
		for(int i = 1; i <= 7; ++i) {
			int now = 0;
			for(int j = i, cnt = 1; j <= i + 6 && cnt <= n; ++j) 
				if(a[j]) ++cnt, ++now;
				else ++now;
			res = min(res, now);
		}
		ans += res;
		printf("%d\n", ans);
	}
	return 0;
}