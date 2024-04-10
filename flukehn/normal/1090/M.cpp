#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int Read() {
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >='0' && ch <='9'){x = x*10 + ch - '0'; ch = getchar();}
	return x*f;
}

const int N = 100005;

int n, k;

int main() {
	n = Read(), k = Read();
	int ans = 0;
	for(int i = 1, x, las = 0, cnt = 0; i <= n; ++i) {
		x = Read();
		if(x == las) cnt = 1;
		else ++cnt;
		ans = max(ans, cnt);
		las = x;
	}
	printf("%d", ans);
}