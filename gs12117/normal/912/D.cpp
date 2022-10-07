#include<cstdio>
#include<queue>
int n, m, r, k;
int a[100100];
long long int b[100100];
int s[100100];
struct st {
	long long int val;
	int d;
	bool operator<(const st&r)const {
		return val < r.val;
	}
};
std::priority_queue<st> pq;
int main() {
	scanf("%d%d%d%d", &n, &m, &r, &k);
	for (int i = 0; i < n; i++) {
		a[i] = i / 2 + 1;
		if (a[i] > r)a[i] = r;
		if (a[i] > n - r + 1)a[i] = n - r + 1;
	}
	for (int i = 0; i < m; i++) {
		b[i] = i / 2 + 1;
		if (b[i] > r)b[i] = r;
		if (b[i] > m - r + 1)b[i] = m - r + 1;
	}
	for (int i = 0; i < n; i++) {
		s[i] = m - 1;
		st tmp;
		tmp.d = i;
		tmp.val = a[i] * b[m - 1];
		pq.push(tmp);
	}
	double ans = 0;
	for (int i = 0; i < k; i++) {
		st x = pq.top();
		pq.pop();
		ans += x.val;
		int y = x.d;
		s[y]--;
		if (s[y] >= 0) {
			st z;
			z.d = y;
			z.val = b[s[y]] * a[y];
			pq.push(z);
		}
	}
	ans /= n - r + 1;
	ans /= m - r + 1;
	printf("%.20lf\n", ans);
	return 0;
}