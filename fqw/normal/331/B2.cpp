#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b); }

const int MAXN=300010;

int tr[MAXN], t[MAXN];
int pos[MAXN], a[MAXN];
int n, qs;

void add(int x, int v) {
	for(; x<=n; x+=(x&-x)) tr[x]+=v;
}
int get(int x) {
	int ans=0;
	for(; x>=1; x-=(x&-x)) ans+=tr[x];
	return ans;
}

void upt(int x) {
	if(x<=1 || x>n) return;
	add(x, -t[x]);
	if(pos[x]<pos[x-1]) t[x]=1; else t[x]=0;
	add(x, t[x]);
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &a[i]), pos[a[i]]=i;
	
	fillchar(tr, 0); t[1]=0;
	forint(i, 2, n) {
		if(pos[i]<pos[i-1]) t[i]=1; else t[i]=0;
		add(i, t[i]);
	}
	scanf("%d", &qs);
	while(qs--) {
		int p, x, y; scanf("%d%d%d",&p,&x,&y);
		if(p==1) {
			int ans=get(y)-get(x)+1;
			printf("%d\n", ans);
		} else {
			swap(a[x], a[y]);
			pos[a[x]]=x; pos[a[y]]=y;
			x=a[x], y=a[y];
			upt(x); upt(x+1);
			upt(y); upt(y+1);
		}
	}
	return 0;
}