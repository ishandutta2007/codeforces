#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back

const int MAXN=100010;
const int MAXC=26;

int cnt[MAXN*4][MAXC];
int buf[MAXN*4];
char str[MAXN];

void push(int x, int s, int t, int c) {
	memset(cnt[x], 0, sizeof(cnt[x]));
	cnt[x][c]=t-s+1;
	buf[x]=c;
}
void release(int x, int s, int t) {
	if(buf[x]<0) return;
	int mid=(s+t)/2;
	push(x*2, s, mid, buf[x]);
	push(x*2+1, mid+1, t, buf[x]);
	buf[x]=-1;
}

void paint(int x, int s, int t, int st, int en, int c) {
//for(int i=st; i<=en; ++i) buf[i]=c; return;
	if(st<=s && t<=en) {
		push(x, s, t, c);
		return;
	}
	release(x, s, t);
	int mid=(s+t)/2;
	if(st<=mid) paint(x*2, s, mid, st, en, c);
	if(mid<en) paint(x*2+1, mid+1, t, st, en, c);
	for(int i=0; i<MAXC; ++i) cnt[x][i]=cnt[x*2][i]+cnt[x*2+1][i];
}

void get(int x, int s, int t, int st, int en, int c[]) {
//for(int i=st; i<=en; ++i) c[buf[i]]++; return;
	if(st<=s && t<=en) {
		for(int i=0; i<MAXC; ++i) c[i]+=cnt[x][i];
		return;
	}
	release(x, s, t);
	int mid=(s+t)/2;
	if(st<=mid) get(x*2, s, mid, st, en, c);
	if(mid<en) get(x*2+1, mid+1, t, st, en, c);
}

int main() {
freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	int n, qs; scanf("%d%d", &n, &qs);
	scanf("%s", str+1);
	memset(buf, 0xff, sizeof(buf));
	memset(cnt, 0, sizeof(cnt));
	for(int i=1; i<=n; ++i)
		paint(1, 1, n, i, i, (int)(str[i]-'a'));
	while(qs--) {
		int c[MAXC]; memset(c, 0, sizeof(c));
		int l, r; scanf("%d%d", &l, &r);
		get(1, 1, n, l, r, c);
		int odds=0;
		for(int i=0; i<MAXC; ++i) if(c[i]%2==1)
			++odds;
		if(odds>1) continue;
		for(int i=0; i<MAXC; ++i) if(c[i]>=2) {
			int sz=c[i]/2;
			paint(1, 1, n, l, l+sz-1, i);
			l+=sz;
		}
		for(int i=0; i<MAXC; ++i) if(c[i]%2==1) {
			paint(1, 1, n, l, l, i);
			++l;
		}
		for(int i=MAXC-1; i>=0; --i) if(c[i]>=2) {
			int sz=c[i]/2;
			paint(1, 1, n, l, l+sz-1, i);
			l+=sz;
		}
		//printf("l=%d r=%d\n",l,r);
	}
	for(int i=1; i<=n; ++i) {
		int c[MAXC]; memset(c, 0, sizeof(c));
		get(1, 1, n, i, i, c);
		for(int i=0; i<MAXC; ++i) if(c[i]>0)
			printf("%c", (char)(i+'a'));
	}
	printf("\n");
	return 0;
}