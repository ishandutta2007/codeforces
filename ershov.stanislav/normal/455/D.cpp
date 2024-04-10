#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=101111;
#else
const int maxn=111;
#endif

int n, q, a[maxn], pr[maxn], nxt[maxn], start[400], cnt[400][maxn], fin, ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]), pr[i]=i-1, nxt[i]=i+1;
	pr[n]=n-1;
	int sq=sqrt(n);
	for (int i=0; (i-1)*sq<=n; i++) {
		start[i]=i*sq;
		for (int j=i*sq; j<(i+1)*sq; j++) cnt[i][a[j]]++;
	}
	scanf("%d", &q);
	for (int i=0; i<q; i++) {
		int t, l, r, k;
		scanf("%d%d%d", &t, &l, &r);
		l=(l+ans-1)%n;
		r=(r+ans-1)%n;
		if (l>r) swap(l, r);
		int ll=l/sq, rr=r/sq;
		int cur1=start[rr], cur2=start[ll];
		for (int j=0; j<r-rr*sq; j++) cur1=nxt[cur1];
		for (int j=0; j<l-ll*sq; j++) cur2=nxt[cur2];
		
		if (t==1) {
			if (l==r) continue;
			if (start[rr]==cur1) start[rr]=nxt[cur1];
			if (start[ll]==cur2) start[ll]=cur1;
			pr[nxt[cur1]]=pr[cur1], nxt[pr[cur1]]=nxt[cur1];
			cnt[rr][a[cur1]]--;
			pr[cur1]=pr[cur2];
			nxt[cur1]=cur2;
			if (pr[cur2]!=-1) nxt[pr[cur2]]=cur1;
			pr[cur2]=cur1;
			cnt[ll][a[cur1]]++;
			for (int j=ll+1; j<=rr; j++) {
				start[j]=pr[start[j]];
				cnt[j-1][a[start[j]]]--;
				cnt[j][a[start[j]]]++;
			}
		} else {
			scanf("%d", &k);
			k=((k+ans-1)%n)+1;
			ans=0;
			for (int j=ll+1; j<rr; j++) ans+=cnt[j][k];
			if (ll!=rr) {
				for (int j=pr[start[ll+1]]; j!=pr[cur2]; j=pr[j]) ans+=(a[j]==k);
				for (int j=start[rr]; j!=nxt[cur1]; j=nxt[j]) if (a[j]==k) ans+=(a[j]==k);
			} else {
				for (int j=cur2; j!=nxt[cur1]; j=nxt[j]) if (a[j]==k) ans+=(a[j]==k);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}