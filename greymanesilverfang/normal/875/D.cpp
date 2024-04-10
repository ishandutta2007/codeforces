#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 2e5 + 1;
stack<int> S;
long long n, a[N], r[N], l[N], res;

inline bool comp(int x, int y) {
	return ((a[x] | a[y]) == a[x]);
}

int main() {
	scanf("%lld", &n); a[n] = 1e15;
	for (int i = 0; i < n; ++i)
		scanf("%lld", &a[i]);
	for (int i = 0; i <= n; S.push(i++))
		while (!S.empty() && (!comp(S.top(), i) || a[S.top()] == a[i]))
			r[S.top()] = i - S.top(), S.pop();
	reverse(a, a + n); S.pop();
	for (int i = 0; i <= n; S.push(i++))
		while (!S.empty() && !comp(S.top(), i))
			l[S.top()] = i - S.top(), S.pop();
	for (int i = 1; i <= n; ++i)
		res -= r[i - 1] * l[n - i];
	printf("%lld", res + n * (n + 1) / 2);
}