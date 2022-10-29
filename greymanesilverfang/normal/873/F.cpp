#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 4e5 + 5;
char s[N], t[N];
int rnk[N], tmp[N], id[N], h[N], l[N], r[N], f[N];
vector<int> v1[N], v2[N];

void suffixsort(int* rnk, int* tmp, vector<int>* v1, vector<int>* v2, int n, int d) {
	for (int i = 0; i < n; ++i)
		v1[rnk[i + d]].push_back(i);
	for (int i = 0; i < max(n + 1, 128); ++i) {
		for (int j = 0; j < v1[i].size(); ++j)
			v2[rnk[v1[i][j]]].push_back(v1[i][j]);
		v1[i].clear();
	}
	for (int i = 0, j = 0; i < max(n + 1, 128); ++i) {
		for (int k = 0; k < v2[i].size(); ++k) {
			int cur = v2[i][k],
			    prv = v2[i][k-(k>0)];
			tmp[cur] = j += cur == prv || rnk[cur + d] != rnk[prv + d];
		}
		v2[i].clear();
	}
	for (int i = 0; i < n; ++i)
		rnk[i] = tmp[i];
}

void histogram(int n, int* h, int* res) {
	stack<int> st; 
	st.push(0);
	for (int i = 0; i < n; st.push(i))
		for (++i; h[i] < h[st.top()]; st.pop())
			res[st.top()] = i - st.top();
}

int main() {
	int n; scanf("%d%s%s", &n, s, t);
	reverse(s, s + n);
	reverse(t, t + n);
	// printf("building lcp array...\n");
	for (int i = 0; i < n; ++i)
		rnk[i] = s[i];
	for (int i = 1; i <= n; i <<= 1)
		suffixsort(rnk, tmp, v1, v2, n, i);
	for (int i = 0; i < n; ++i)
		id[rnk[i] - 1] = i;
	id[n] = n;
	for (int i = 0, x = 0; i < n; h[rnk[i++]] = x--)
		while (!~x || s[i + x] == s[id[rnk[i]] + x]) ++x;
	// printf("solving histogram...\n");
	h[0] = h[n] = -1;
	reverse(h + 1, h + n);
	histogram(n, h, l);
	reverse(h + 1, h + n);
	histogram(n, h, r);
	reverse(l + 1, l + n);
	// printf("forbidding indices...\n");
	for (int i = 0; i < n; ++i)
		f[rnk[i]] = t[i] == '0';
	for (int i = 1; i <= n; ++i)
		f[i] += f[i - 1];
	// printf("finding answer...\n");
	long long res = 0;
	for (int i = 0; i < n; ++i)
		if (t[i] == '0') {
			res = n - i;
			break;
		}
	for (int i = 1; i < n; ++i)
		res = max(res, (long long) h[i] * (f[i + r[i]] - f[i - l[i]]));
	printf("%lld", res);
}