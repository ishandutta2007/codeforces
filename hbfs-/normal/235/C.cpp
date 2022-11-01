#include <bits/stdc++.h>
#define N 1000050
#define Z 26
using namespace std;

int d[2*N],F[2*N],len[2*N],ch[2*N][Z],lnk[2*N],lst,rt;
int nex[N],n,m,ans,cur,p,k,tot;
char s[N],t[N];

void add(int pos) {
	int c = s[pos]-'a', p = lst, np = lst = ++tot;
	len[np] = len[p] + 1;
	F[np] = 1;
	while (p && !ch[p][c]) ch[p][c] = np, p = lnk[p];
	if (!p) {lnk[np] = rt; return ;}
	int q = ch[p][c];
	if (len[q] == len[p] + 1)
		lnk[np] = q;
	else {
		int nq = ++tot;
		len[nq] = len[p] + 1;
		memcpy(ch[nq],ch[q],sizeof(ch[q]));
		lnk[nq] = lnk[q];
		lnk[q] = lnk[np] = nq;
		while (p && ch[p][c] == q) ch[p][c] = nq, p = lnk[p];
	}
}

int bd() {
	int j=0; nex[1] = 0;
	for (int _=2;_<=m;_++) {
		while (j && t[j+1] != t[_]) j = nex[j];
		if (t[j+1] == t[_]) j++;
		nex[_] = j;
	}
	int ret = m - nex[m];
	if (ret > m/2) return m;
	if (m % ret == 0) return ret; else return m;
}

void g(int x) {
	int c = t[x]-'a';
	while (p && !ch[p][c]) p = lnk[p], cur = len[p];
	if (!p)
		p = rt, cur = 0;
	else
		p = ch[p][c], cur++;
	if (cur == m) {
		ans += F[p];
		if (--cur <= len[lnk[p]]) p = lnk[p];
	}
}

int main() {
	scanf("%s",s+1); n = strlen(s+1);
	
	lst = rt = ++tot;
	for (int _=1;_<=n;_++) add(_);

	queue<int> q;
	for (int _=1;_<=tot;_++) d[lnk[_]]++;
	for (int _=1;_<=tot;_++) if (!d[_]) q.push(_);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		F[lnk[u]] += F[u];
		if (--d[lnk[u]] == 0) q.push(lnk[u]);
	}

	int Q=0; scanf("%d",&Q);
	while (Q--) {
		scanf("%s",t+1); m = strlen(t+1);
		k = bd(), ans = 0;
		for (int _=1;_<=m;_++) t[_+m] = t[_];
		
		p = rt, cur = 0;
		for (int _=1;_<=m+k-1;_++) g(_);
		printf("%d\n",ans);
	}
	return 0;
}