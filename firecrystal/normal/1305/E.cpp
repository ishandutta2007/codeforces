#include <iostream>
#include <cstdio>
using namespace std;
const int N = 5005, INF = 1e9;
typedef long long LL;
int n, m, p, a[N], cnt[N << 1];
LL ans = 0;
int main() {
	scanf("%d%d", &n, &m);
	if (m == 0) {
	    if (n == 1) {
	        cout << "1";
	        return 0;
	    } else if(n == 2) {
	        cout << "1 2";
	        return 0;
	    }
	    cout << "1 2 ";
	    a[2] = 2;
	    for (int i = 3; i <= n; i++) a[i] = a[i - 1] + 3, cout << a[i] << " ";
	    return 0;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		int v = (i - 1) / 2;
		if (ans == m) {
		    a[i] = a[i - 1] + p;
		} else if (ans + v > m) {
			for (int j = 1; j < i; j++) {
				for (int k = j + 1; k < i; k++) {
					cnt[j + k] ++;
				}
			}
			int o = m - ans;
			for (int k = i + 1; k <= i + i; k++) {
				if (cnt[k] == o) {
					a[i] = k;
					break;
				}
			}
			ans = m;
			p = i;
		} else {
		    ans += v;
			if (ans == m) p = i + 1;
		}
	}
	if (ans < m) puts("-1");
	else for (int i = 1; i <= n; i++) printf("%d ", a[i]);
	return 0;
}