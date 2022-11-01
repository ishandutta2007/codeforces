#include <bits/stdc++.h>
#define N 1050
using namespace std;
int ox[20050],oy[20050],oz[20050],a[N],b[N],n,k,m,tot,blank;

inline int rd() {int r;scanf("%d",&r);return r;}

void park(int x) {
	++m;
	if (x <= n)
		ox[m] = a[x], oy[m] = 1, oz[m] = x;
	else
		ox[m] = a[x], oy[m] = 4, oz[m] = n-(x-n)+1;
	b[x] = 0;
}

void shl(int x) {
	if (!b[x]) return ;
	++m; ox[m] = b[x];
	if (x == 1) {
		oy[m] = 3, oz[m] = 1;
		swap(b[2*n], b[1]);
		return ;
	}
	if (x == n+1) {
		oy[m] = 2, oz[m] = n;
		swap(b[n+1], b[n]);
		return ;
	}
	
	if (x <= n) {
		oy[m] = 2, oz[m] = x-1;
		swap(b[x], b[x-1]);
	} else {
		oy[m] = 3, oz[m] = n-(x-1-n)+1;
		swap(b[x], b[x-1]);
	}
}

int main() {
	n = rd(), k = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=1;i<=n;i++) b[i] = rd();
	for (int i=2*n;i>=n+1;i--) b[i] = rd();
	for (int i=2*n;i>=n+1;i--) a[i] = rd();

	for (int i=1;i<=2*n;i++)
		if (a[i] == b[i] && a[i]>0)
			park(i), tot++, blank = i;
   	for (int i=1;i<=2*n;i++) if (!b[i]) blank = i;
   	
   	if (!blank) {
   		puts("-1");
   		return 0;
   	}
   	
   	while (tot < k) {
   		for (int i=1;i<=2*n-1;i++) {
   			int x = blank + i;
   			if (x > 2*n) x -= 2*n;
			shl(x);
   		}
		--blank;
		if (!blank) blank = 2*n;
   		for (int i=1;i<=2*n;i++) if (a[i] == b[i] && a[i]>0) park(i), tot++;
   	}
   	
   	printf("%d\n",m);
   	for (int i=1;i<=m;i++) printf("%d %d %d\n",ox[i],oy[i],oz[i]);
	return 0;
}