#include <bits/stdc++.h>
#define N 35050
#define mid ((l+r)>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1
using namespace std;
inline int rd() {
	int x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

int ag[4*N],tr[4*N],ll,rr,v;
int F[N],G[N],tmp[N];
int n,k,a[N];

void push_down(int t) {
	tr[t<<1] += ag[t], tr[t<<1^1] += ag[t];
	ag[t<<1] += ag[t], ag[t<<1^1] += ag[t];
	ag[t] = 0;
}

int build(int l,int r,int t) {
	ag[t] = 0;
	return tr[t] = l==r ? 0 : build(ls) + build(rs);
}

void update(int l,int r,int t) {
	if (l > rr || r < ll) return ;
	if (l >= ll && r <= rr) {
		tr[t] += v, ag[t] += v;
		return ;
	}
	if (ag[t]) push_down(t);
	update(ls);
	update(rs);
	tr[t] = max(tr[t<<1], tr[t<<1^1]);
}

int main() {
	n = rd(), k = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int _=1;_<=k;_++) {
		memset(tmp,0,sizeof(tmp));
		for (int i=1;i<=n;i++) G[i] = F[i];
		build(1,n,1);
		for (int i=1;i<=n;i++) {
			if (tmp[ a[i] ]) {
				ll = 1, rr = tmp[a[i]], v = -1;
				update(1,n,1);
			}
			ll = 1, rr = tmp[a[i]] = i, v = 1;
			update(1,n,1);
			F[i] = tr[1];
			if (i!=n) {
				ll = rr = i+1, v = G[i];
				update(1,n,1);
			}
		}
	}
	printf("%d\n",F[n]);
	return 0;
}