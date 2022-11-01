#include <bits/stdc++.h>
#define N 1000500
using namespace std;
typedef long long LL;
inline int rd() {int r;scanf("%d",&r);return r;}
int n,m,k,tp;
int a[N],s[N],f[N];
LL ans;

int main() {
	n = rd(), k = rd(), m = rd();
	for (int _=1;_<=n;_++) a[_] = rd();
	if (k >= n) {
		bool flag = 1;
		for (int _=1;_<=n;_++) if (a[_] != a[1]) flag = 0;
		if (flag)
			cout << 1LL*n*m%k << endl;
		else
			cout << 1LL*n*m << endl;
		return 0;
	}
	
	
	for (int _=1;_<=n;_++) {
		s[++tp] = a[_];
		if (tp>1 && s[tp]==s[tp-1])
			f[tp] = f[tp-1] + 1;
		else
			f[tp] = 1;
		if (f[tp] == k) tp -= k;
	}
	
	int L = 1, R = tp;
	while (s[L]==s[R] && L!=R) {
		int l = L, r = R, cnt = 0;
		while (s[L]==s[l] && l<r && cnt<k) ++l, ++cnt;
		while (s[R]==s[r] && l<r && cnt<k) --r, ++cnt;
		if (cnt == k)
			L = l, R = r, ans += k;
		else
			break; 
	}
	
	bool flag = 1;
	for (int _=L+1;_<=R;_++)
		if (s[_] != s[L]) flag = 0;
	if (flag) {
		if (1LL * (R-L+1)*m%k == 0)
			puts("0");
		else
			cout << 1LL*(R-L+1)*m%k+ans << endl;
	} else {
		cout << ans+1LL*(R-L+1)*m << endl;
	} 
	return 0;
}