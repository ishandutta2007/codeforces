#include <bits/stdc++.h>
#define N 3000500
using namespace std;

int n,k;
int vis[30], L[30], tmpvis[30], tmpL[30];

char A[N],B[N],S[N];
int a[N],b[N],s[N];

inline int rd() {int r;scanf("%d",&r);return r;}

bool add(int d, int c) {
	if (L[s[d]] == c) return 1;
	if (!L[s[d]] && !vis[c]) {
		L[s[d]] = c;
		vis[c] = 1;
		return 1;
	}
	return 0;
}

void o() {
	for (int i=1;i<=k;i++) if (!L[i]) {
		for (int j=1;j<=k;j++) if (!vis[j]) {
			L[i] = j;
			vis[j] = 1;
			break;
		}
	}

	puts("YES");
	for (int i=1;i<=k;i++) putchar(L[i] + 'a' - 1);
	putchar('\n');
	return ;
}

void solve() {
	k = rd();
	scanf("%s",S+1);
	scanf("%s",A+1);
	scanf("%s",B+1);
	n = strlen(S+1);

	memset(L, 0, sizeof(L));
	memset(vis, 0, sizeof(vis));
	memset(tmpvis, 0, sizeof(tmpvis));
	memset(tmpL, 0, sizeof(tmpL));

	for (int i=1;i<=n;i++) s[i] = S[i] - 'a' + 1;
	for (int i=1;i<=n;i++) a[i] = A[i] - 'a' + 1;
	for (int i=1;i<=n;i++) b[i] = B[i] - 'a' + 1;
	
	int d = 0;
	for (int i=1;i<=n;i++) {
		if (a[i] != b[i]) {
			d = i;
			break;
		} else {
			bool cur = add(i, a[i]);
			if (!cur) {
				puts("NO");
				return ;
			}
		}
	}

	if (!d) {
		o();
		return ;
	} else {
		for (int i=a[d]+1;i<=b[d]-1;i++)
			if (add(d, i)) {
				o();
				return ;
			}

		for (int i=1;i<=k;i++) tmpL[i] = L[i], tmpvis[i] = vis[i];
		
		
		bool cur;

		cur = add(d, a[d]);
		if (cur) {
			bool flag = 1;
			for (int i=d+1;i<=n;i++) {
				for (int _=a[i]+1;_<=k;_++) if (add(i, _)) {
					o();
					return ;
				}

				if (add(i, a[i])) {
					
				} else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				o();
				return ;
			}
			
		}

		for (int i=1;i<=k;i++) L[i] = tmpL[i], vis[i] = tmpvis[i];

		cur = add(d, b[d]);
		if (cur) {
			bool flag = 1;
			for (int i=d+1;i<=n;i++) {
				for (int _=1;_<=b[i]-1;_++) if (add(i, _)) {
					o();
					return ;
				}

				if (add(i, b[i])) {

				} else {
					flag = 0;
					break;
				}
			}
			if (flag) {
				o();
				return ;
			}
		}
	}
	puts("NO");
	return ;
}

int main() {
	for (int T=rd();T;T--) solve();
	return 0;
}