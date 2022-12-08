#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))

const int MAXN=100010;
const int V=3*100000+10;

struct P {
	int l, v, r, ind;
	bool operator <(const P &p) const {
		return v<p.v;
	}
} a[MAXN];
int n;

VI head[V];
PII tr[V*4];
int ts[V*4];

PII operator +(const PII &a, const PII &b) {
	return MP(a.fi+b.fi, a.se+b.se);
}

void build(int x, int s, int t) {
	if(s==t) {
		tr[x]=MP(0, s);
		ts[x]=0;
		return;
	}
	int mid=(s+t)/2;
	build(x*2, s, mid);
	build(x*2+1, mid+1, t);
	tr[x]=max(tr[x*2], tr[x*2+1]+MP(ts[x*2],0));
	ts[x]=ts[x*2]+ts[x*2+1];
}

void add(int x, int s, int t, int ind, int val) {
	if(s==t) {
		ts[x]+=val;
		tr[x].fi+=val;
		return;
	}
	int mid=(s+t)/2;
	if(ind<=mid) add(x*2, s, mid, ind, val);
		else add(x*2+1, mid+1, t, ind, val);
	tr[x]=max(tr[x*2], tr[x*2+1]+MP(ts[x*2],0));
	ts[x]=ts[x*2]+ts[x*2+1];
}

void ins(int i) {
	add(1, 1, V, a[i].v, 1);
	add(1, 1, V, a[i].r+1, -1);
}
void del(int i) {
	add(1, 1, V, a[i].v, -1);
	add(1, 1, V, a[i].r+1, 1);
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d%d%d", &a[i].l,&a[i].v,&a[i].r), a[i].ind=i;
	sort(a+1, a+n+1);

	build(1, 1, V);
	int curhead=V;
	int ans=0, ansl, ansr;
	forintdown(i, n, 1) {
		while(curhead>a[i].v) {
			forn(k, head[curhead].size())
				del(head[curhead][k]);
			--curhead;
		}
		ins(i);
		head[a[i].l].PB(i);
		PII p=tr[1];
	//printf("i=%d v=%d p=(%d,%d)\n",i,a[i].v,p.fi,p.se);
		if(p.fi>ans) {
			ans=p.fi;
			ansl=a[i].v;
			ansr=p.se;
		}
	}

//printf("[%d, %d]\n", ansl, ansr);
	printf("%d\n", ans);
	forint(i, 1, n) if(a[i].l<=ansl && a[i].r>=ansr && a[i].v>=ansl && a[i].v<=ansr)
		printf("%d ", a[i].ind);
	printf("\n");
	
	return 0;
}