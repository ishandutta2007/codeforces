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

const int MAXN=1001000;

struct P {
	int a, b; // a * ) + b * (
	friend P operator +(P x, P y) {
		int a=x.a, b=y.b;
		int tmp=min(x.b, y.a);
		x.b-=tmp;
		y.a-=tmp;
		if(x.b>0) b+=x.b;
		if(y.a>0) a+=y.a;
		P t;
		t.a=a, t.b=b;
		return t;
	}
};

P tr[MAXN*4];
char a[MAXN];
int n;

void build(int x, int s, int t) {
	if(s==t) {
		if(a[s]==')')
			tr[x].a=1, tr[x].b=0;
		else
			tr[x].a=0, tr[x].b=1;
		return;
	}
	int mid=(s+t)/2;
	build(x*2, s, mid);
	build(x*2+1, mid+1, t);
	tr[x]=tr[x*2]+tr[x*2+1];
}

P get(int x, int s, int t, int st, int en) {
	if(st<=s && t<=en)
		return tr[x];
	int mid=(s+t)/2;
	if(en<=mid) return get(x*2, s, mid, st, en);
	if(mid<st) return get(x*2+1, mid+1, t, st, en);
	return get(x*2, s, mid, st, en)+get(x*2+1, mid+1, t, st, en);
}

int main() {
	scanf("%s", a+1);
	n=strlen(a+1);
	build(1, 1, n);
	int q; scanf("%d", &q);
	while(q--) {
		int s, t; scanf("%d%d", &s,&t);
		P p=get(1, 1, n, s, t);
		int ans=t-s+1-p.a-p.b;
		printf("%d\n", ans);
	}
	return 0;
}