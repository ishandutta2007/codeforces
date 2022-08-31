#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 131072 * 8;
int b[N + N];

int get(int v, int l1, int r1, int l, int r){
	if (l < l1)
		l = l1;
	if (r > r1)
		r = r1;
	if (l > r1 || l1 > r || l > r)
		return INT_MAX;
	if (l == l1 && r == r1)
		return b[v];
	int m = (l1 + r1) / 2;
	return min(get(v * 2, l1, m, l, r), get(v * 2 + 1, m + 1, r1, l, r));
}

int main(){

	int n = nxt();
	vector<int> a(n + n + n);
	for (int i = 0; i < n; i++)
		a[i] = 0;
	for (int i = 0; i < n; i++){
		a[n + i] = nxt();
	}
	for (int i = 0; i < n; i++)
		a[n + n + i] = 0;
	n = 3 * n;
	for (int i = 0; i < N; i++)
		if (i < n)
			b[N + i] = a[i] + i;
		else
			b[N + i] = INT_MAX;
	for (int i = N - 1; i > 0; i--){
		b[i] = min(b[i * 2], b[i * 2 + 1]);
	}
	int ans = 0;
	int cur = INT_MAX - 10;
	for (int i = 0; i <= n / 2; i++){
		cur = min(cur + 1, a[i]);
		ans = max(ans, min(cur, get(1, 0, N - 1, i + 1, i * 2) - i));
	}
	
	reverse(all(a));
	for (int i = 0; i < N; i++)
		if (i < n)
			b[N + i] = a[i] + i;
		else
			b[N + i] = INT_MAX;
	for (int i = N - 1; i > 0; i--){
		b[i] = min(b[i * 2], b[i * 2 + 1]);
	}
	cur = INT_MAX - 10;
	for (int i = 0; i <= n / 2; i++){
		cur = min(cur + 1, a[i]);
		ans = max(ans, min(cur, get(1, 0, N - 1, i + 1, i * 2) - i));
	}

	cout << ans << "\n";

	return 0;
}