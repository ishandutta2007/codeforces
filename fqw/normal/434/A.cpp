#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef vector<int> VI;
typedef pair<double,double> PDD;

const int MAXN=100010;
const int MAXM=100010;

int fi[MAXM], nxt[MAXN];
int a[MAXN], n, m;

LL lst[MAXN*2], sum[MAXN*2]; int len;

int main() {
	scanf("%d%d", &m, &n);
	forint(i, 1, n) scanf("%d", &a[i]);
	fillchar(fi, 0);
	forintdown(i, n, 1) {
		nxt[i]=fi[a[i]];
		fi[a[i]]=i;
	}
	LL ans=0;
	forn(v, MAXM) if(fi[v]>0) {
		len=0;
		for(int i=fi[v]; i; i=nxt[i]) {
			if(i>1 && a[i-1]!=a[i]) lst[++len]=a[i-1];
			if(i<n && a[i+1]!=a[i]) lst[++len]=a[i+1];
		}
		sort(lst+1, lst+len+1);
		LL cur=0;
		forint(i, 1, len) cur-=abs(v-lst[i]);
		sum[0]=0;
		forint(i, 1, len) sum[i]=sum[i-1]+lst[i];
		forint(i, 1, len) {
			LL tmp=cur;
			tmp+=LL(lst[i])*i-sum[i];
			tmp+=(sum[len]-sum[i])-LL(lst[i])*(len-i);
			ans=min(ans, tmp);
		}
	}
	forint(i, 2, n) ans+=abs(a[i]-a[i-1]);
	cout<<ans<<endl;
	return 0;
}