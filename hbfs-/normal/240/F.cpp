#include <bits/stdc++.h>
#define N 100050

#define mid ((l+r)>>1)
#define ls l,mid,t<<1
#define rs mid+1,r,t<<1^1

using namespace std;

int n,m,v,ll,rr,ret,cur[30];
char s[N];
inline int rd() {int r;scanf("%d",&r);return r;}
struct Node{int sum,siz;}tr[4*N],id;
Node operator+(Node p1, Node p2) {
	Node ret = id;
	ret.sum = p1.sum + p2.sum;
	ret.siz = p1.siz + p2.siz;
	return ret;
}
struct Segment_Tree{
	Node tr[4*N];
	int a[N],ag[4*N];

	Node build(int l,int r,int t) {
		ag[t] = -1;
		return tr[t] = l==r ? (Node){a[l],1} : build(ls) + build(rs);
	}

	void push_down(int t) {
		if (ag[t] == -1) return ;
		tr[t<<1].sum = ag[t] * tr[t<<1].siz;
		tr[t<<1^1].sum = ag[t] * tr[t<<1^1].siz;
		ag[t<<1] = ag[t<<1^1] = ag[t];
		ag[t] = -1;
	}

	void update(int l,int r,int t) {
		if (l > rr || r < ll) return ;
		if (ag[t] == v) return ;
		if (l >= ll && r <= rr) {
			ag[t] = v;
			tr[t].sum = v * tr[t].siz;
			return ;
		}
		push_down(t);
		update(ls); update(rs);
		tr[t] = tr[t<<1] + tr[t<<1^1];
	}

	void query(int l,int r,int t) {
		if (l > rr || r < ll) return ;
		if (ag[t] != -1) return ret += ag[t] * (min(rr,r)-max(ll,l)+1), (void)0;
		if (l >= ll && r <= rr) return ret += tr[t].sum, (void)0;
		push_down(t);
		query(ls); query(rs);
	}

}T[27];

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n = rd(), m = rd();
	scanf("%s",s+1);

	for (int _=1;_<=n;_++) T[s[_]-'a'].a[_] = 1;
	for (int _=0;_<26;_++) T[_].build(1,n,1);
	while (m--) {
		int l = rd(), r = rd(), d = -1, flag = 0;
		for (int _=0;_<26;_++) {
			ret = 0, ll = l, rr = r;
			T[_].query(1,n,1);
			cur[_] = ret / 2;
			if (ret&1) {
				if (d == -1 && (r-l+1)%2 == 1) d = _;else {flag = 1; break;}
			}
		}

		if (flag) continue;
		for (int _=1;_<26;_++) cur[_] += cur[_-1];
		for (int _=0;_<26;_++) {
			v = 1;
			if (!_) ll = l; else ll = l+cur[_-1];
			rr = l+cur[_]-1;
			if (ll <= rr) T[_].update(1,n,1);

			v = 0, rr = ll-1, ll = l;
			if (ll <= rr) T[_].update(1,n,1);

			v = 1;
			ll = r-cur[_]+1;
			if (!_) rr = r; else rr = r-cur[_-1];
			if (ll <= rr) T[_].update(1,n,1);

			v = 0, ll = rr+1, rr = r;
			if (ll <= rr) T[_].update(1,n,1);

			v = 0, ll = l+cur[_], rr = r-cur[_];
			if (ll <= rr) T[_].update(1,n,1);
		}

		if (~d) v = 1, ll = rr = (l+r)>>1, T[d].update(1,n,1);

	}

	for (int _=1;_<=n;_++) {
		ret = 0;
		for (int i=0;i<26;i++) {
			ll = rr = _, T[i].query(1,n,1);
			if (ret) {putchar('a'+i);break;}
		}
	}
	puts("");
	return 0;
}