#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

const int MAXN=1000010;

struct Node {
	int val, ran;
	int l, r;
	int size;
} tr[MAXN*2]; int n_cnt;
int root;
int del_key;

void update(int x) {
	tr[x].size=tr[tr[x].l].size+tr[tr[x].r].size+1;
}

int lrotate(int x) {
	int y=tr[x].l;
	tr[x].l=tr[y].r;
	tr[y].r=x;
	update(x); update(y);
	return y;
}
int rrotate(int x) {
	int y=tr[x].r;
	tr[x].r=tr[y].l;
	tr[y].l=x;
	update(x); update(y);
	return y;
}

int ins(int x, int ind, int key) {
	if(x==0) {
		x=++n_cnt;
		tr[x].val=key; tr[x].ran=rand();
		tr[x].l=tr[x].r=0;
		tr[x].size=1;
		return x;
	}
	int ci=tr[tr[x].l].size+1;
	if(ind<ci) {
		tr[x].l=ins(tr[x].l, ind, key);
		if(tr[tr[x].l].ran>tr[x].ran)
			x=lrotate(x);
	} else {
		tr[x].r=ins(tr[x].r, ind-ci, key);
		if(tr[tr[x].r].ran>tr[x].ran)
			x=rrotate(x);
	}
	update(x);
	return x;
}

int del(int x, int ind) {
	int ci=tr[tr[x].l].size+1;
	if(ind==ci || ind<0) {
		if(tr[x].l==0 && tr[x].r==0) {
			del_key=tr[x].val;
			return 0;
		}
		if(tr[tr[x].l].ran>tr[tr[x].r].ran) {
			x=lrotate(x);
			tr[x].r=del(tr[x].r, -1);
		} else {
			x=rrotate(x);
			tr[x].l=del(tr[x].l, -1);
		}
		update(x);
		return x;
	}
	if(ind<ci) {
		tr[x].l=del(tr[x].l, ind);
	} else {
		tr[x].r=del(tr[x].r, ind-ci);
	}
	update(x);
	return x;
}

int x[MAXN], y[MAXN];
int n, m;
int a[MAXN];

void p(int x) {
	if(x==0) return;
	p(tr[x].l);
	printf("%d ", tr[x].val);
	p(tr[x].r);
}

int main() {
	scanf("%d%d", &n,&m);
	forint(i, 1, m) scanf("%d%d", x+i,y+i);

	n_cnt=0;
	root=0; tr[0].size=0; tr[0].ran=-1;
	forint(i, 1, n) root=ins(root, 0, -1);

	bool flag=true;
	forintdown(i, m, 1) {
		root=del(root, 1);
		int k=del_key;
		if(k>0 && k!=x[i]) {
			flag=false; break;
		}
		//printf("i=%d k=%d\n", i,k);
		//p(root); printf("\n");
		root=ins(root, y[i]-1, x[i]);
		//p(root); printf("\n");
	}
	if(!flag) printf("-1\n");
	else {
		static bool used[MAXN]; fillchar(used, false);
		forint(i, 1, n) {
			root=del(root, 1);
			a[i]=del_key;
			if(a[i]>0) {
				if(used[a[i]]) {
					flag=false;
					break;
				}
				used[a[i]]=true;
			}
		}
		if(!flag) printf("-1\n");
		else {
			int cur=1;
			forint(i, 1, n) {
				if(a[i]>0) continue;
				while(used[cur]) ++cur;
				a[i]=cur; used[cur]=true;
			}
			forint(i, 1, n) printf("%d ", a[i]); printf("\n");

			/*
			bool ok=true;
			n_cnt=0;
			root=0;
			forintdown(i, n, 1) root=ins(root, 0, a[i]);
			forint(i, 1, m) {
				root=del(root, y[i]);
				if(del_key!=x[i]) ok=false;
				root=ins(root, 0, x[i]);
			}
			if(!ok) for(;;);
			*/
		}
	}

	return 0;
}