#include <iostream>
#include <algorithm>
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

const int MAXN=300000+100;

int x[MAXN], y[MAXN], n, p;
int s[MAXN];
VI d[MAXN];

int tr[MAXN*2];
void add(int x, int v) {
	for(; x<=n*2; x+=(x&-x)) tr[x]+=v;
}
int get(int x) {
	int ans=0;
	for(; x>=1; x-=(x&-x)) ans+=tr[x];
	return ans;
}

int main() {
	scanf("%d%d", &n,&p);
	fillchar(s, 0);
	forint(i, 1, n) d[i].clear();
	forint(i, 1, n) {
		scanf("%d%d", x+i,y+i);
		if(x[i]>y[i]) swap(x[i], y[i]);
		s[x[i]]++;
		s[y[i]]++;
		d[x[i]].PB(y[i]);
	}
	LL ans=0;
	fillchar(tr, 0);
	forint(i, 1, n) add(n*2-s[i], 1);
	forint(i, 1, n) {
		add(n*2-s[i], -1);
		forn(k, d[i].size()) {
			int j=d[i][k];
			add(n*2-s[j], -1);
			--s[j];
			add(n*2-s[j], +1);
		}
		int need=max(0, p-s[i]);
		int cnt=get(n*2-need);
		ans+=cnt;
		forn(k, d[i].size()) {
			int j=d[i][k];
			add(n*2-s[j], -1);
			++s[j];
			add(n*2-s[j], +1);
		}
	}
	cout<<ans<<endl;
	return 0;
}