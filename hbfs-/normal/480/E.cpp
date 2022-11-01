#include <bits/stdc++.h>
#define N 2050
using namespace std;
int n,m,q,a[N][N],L[N][N],R[N][N],x[N],y[N],ans[N];
int ql[N],qr[N];
char s[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), m = rd(), q = rd();
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) a[i][j] = s[j] == '.';
	}
		
	for (int _=1;_<=q;_++) {
		x[_] = rd(), y[_] = rd();
		a[x[_]][y[_]] = 0;
	}
	
	for (int i=1;i<=n;i++) {
		L[i][0] = 0, R[i][m+1] = m+1;
		for (int j=1;j<=m;j++)
			L[i][j] = !a[i][j] ? j : L[i][j-1];
		for (int j=m;j>=1;j--)
			R[i][j] = !a[i][j] ? j : R[i][j+1];
	}

	for (int j=1;j<=m;j++) {
		int l = 0, r = m+1, h = 0;
		for (int i=1;i<=n;i++) {
			if (a[i][j]) {
				h++;
				l = max(l, L[i][j]);
				r = min(r, R[i][j]);
				ans[q] = max(ans[q], min(h, r-l-1));
			} else
				l = 0, r = m+1, h = 0;
		}
	}

	for (int _=q;_>=2;_--) {
		int cur = ans[_];
		a[x[_]][y[_]] = 1;
		for (int i=1;i<=m;i++) L[x[_]][i] = a[x[_]][i] ? L[x[_]][i-1] : i;
		for (int i=m;i>=1;i--) R[x[_]][i] = a[x[_]][i] ? R[x[_]][i+1] : i;
		
		for (int flag=0;;flag=0) {
			int hl = 1, tl = 0, hr = 1, tr = 0;
			for (int i=1;i<=cur;i++) {
				while (hl <= tl && L[i][y[_]] >= L[ql[tl]][y[_]]) --tl;
				ql[++tl] = i;
				while (hr <= tr && R[i][y[_]] <= R[qr[tr]][y[_]]) --tr;
				qr[++tr] = i;
			}
			for (int i=cur+1;i<=n;i++) {
				while (hl <= tl && L[i][y[_]] >= L[ql[tl]][y[_]]) --tl;
				ql[++tl] = i;
				while (hr <= tr && R[i][y[_]] <= R[qr[tr]][y[_]]) --tr;
				qr[++tr] = i;
				if (R[qr[hr]][y[_]]-L[ql[hl]][y[_]]-1 >= cur+1) {flag=1;break;}
				if (ql[hl] == i-cur) ++hl;
				if (qr[hr] == i-cur) ++hr;
			}
			if (flag) cur++; else break;
		}
		ans[_-1] = cur;
	}
	for (int _=1;_<=q;_++) printf("%d\n",ans[_]);
	return 0;
}