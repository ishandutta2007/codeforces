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

int n, k, used[N], b[N];
ll ans = 0;
struct E {
	int a, b;
}a[N];
bool cmp(E a, E b) {return a.b < b.b;}

int main() {
	n = Read(), k = Read();
	for(int i = 1; i <= n; ++i) a[i].a = Read();
	for(int j = 1; j <= n; ++j) a[j].b = Read();
	sort(a + 1, a + 1 + n, cmp);
	int cnt = 1;
	for(int i = n; i >= 1; --i)
		if(!b[a[i].a])
			used[i] = 1, b[a[i].a] = 1, ++cnt;
	for(int i = 1; i <= n && cnt <= k; ++i) 
		if(!used[i])
			ans += a[i].b, ++cnt;
	printf("%lld", ans);
	return 0;
}