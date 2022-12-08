#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN=70010;
const int MAXS=70010;
const int MAXT=MAXS / 32 + 1;
#define fi first
#define se second
typedef pair<int,int> PII;
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef unsigned int UL;

PII a[MAXN];
int n, s, t;

UL f[MAXT], cf[MAXT];
int last[MAXS];
bool used[MAXN];
int ansx[MAXN], ansy[MAXN];
int _log[1<<16];

int main() {
	forint(i, 0, 15) _log[1<<i] = i;
	scanf("%d%d", &n,&s);
	forint(i, 1, n) scanf("%d", &a[i].fi), a[i].se=i;
	sort(a+1, a+n+1);
	if(a[n].fi>s) { printf("-1\n"); return 0; }
	s-=a[n].fi;
	t=(s-1)/32+1;

	fillchar(last, 0);
	fillchar(f, 0);
	f[0]|=1;
	forint(i, 1, n-1) {
		fillchar(cf, 0);
		int x=a[i].fi>>5;
		int y=a[i].fi&31;
		forint(j, 0, t) {
			if(j+x<=t)
				cf[j+x]|=(f[j]<<y);
			if(j+x<t && y>0)
				cf[j+x+1]|=(f[j]>>(32-y));
		}
		forint(j, 0, t) {
			UL more=(cf[j]|f[j])^f[j];
			for(UL tmp=more, b; tmp>0; tmp^=b) {
				b=tmp&(tmp^(tmp-1));
				int x;
				if(b>=(1<<16))
					x=_log[b>>16]+16;
				else
					x=_log[b];
				last[j*32+x]=i;
			}
			f[j]|=more;
		}
	}
	if(f[s>>5]&(UL(1)<<(s&31))) {
		fillchar(used, false);
		for(int s0=s; s0>0; s0-=a[last[s0]].fi)
			used[last[s0]]=true;
		int p=0;
		forint(i, 1, n) {
			ansx[a[i].se]=a[i].fi;
			ansy[a[i].se]=0;
			if(p>0) {
				ansx[a[i].se]-=a[p].fi;
				ansy[a[i].se]=a[p].se;
			}
			if(used[i]) p=0;
				else p=i;
		}
		forint(i, 1, n) {
			if(ansy[i]>0)
				printf("%d 1 %d\n", ansx[i], ansy[i]);
			else
				printf("%d 0\n", ansx[i]);
		}
	} else
		printf("-1\n");
	
	return 0;
}