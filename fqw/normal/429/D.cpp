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
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;

const int MAXN=100010;

int a[MAXN]; LL s[MAXN];
int n;
PLL t[MAXN];
LL ans;

LL sqr(LL x) {
	return x*x;
}

PLL z[MAXN];

void go(int le, int ri) {
	if(le==ri) return;
	int mi=(le+ri)/2;
	LL bound=t[mi].se;
	go(le, mi);
	go(mi+1, ri);
	vector<PLL> tl, tr;
	forint(i, le, mi) if(sqr(t[i].se-bound)<ans) tl.PB(t[i]);
	forint(i, mi+1, ri) if(sqr(t[i].se-bound)<ans) tr.PB(t[i]);
	size_t j=0;
	forn(i, tl.size()) {
		while(j<tr.size() && tr[j].fi<tl[i].fi && sqr(tr[j].fi-tl[i].fi)>=ans)
			++j;
		for(size_t k=j; k<tr.size(); ++k) {
			if(tr[k].fi>tl[i].fi && sqr(tr[k].fi-tl[i].fi)>=ans) break;
			ans=min(ans, sqr(tr[k].fi-tl[i].fi)+sqr(tr[k].se-tl[i].se));
		}
	}
	//sort(t+le, t+ri+1);
	{
		int i=le, j=mi+1, k=le;
		while(i<=mi && j<=ri)
			if(t[i]<t[j]) z[k++]=t[i++];
			else z[k++]=t[j++];
		while(i<=mi) z[k++]=t[i++];
		while(j<=ri) z[k++]=t[j++];
		forint(i, le, ri) t[i]=z[i];
	}
}

int main() {
	//srand(100);
	//while(1) {
	scanf("%d", &n); //++n;
	forint(i, 1, n) scanf("%d", &a[i]);
	//n=5; forint(i, 2, n) a[i]=rand()%10-5;
	//forint(i, 2, n) printf("%d ",a[i]);printf("\n");
	a[0]=0, s[0]=0;
	forint(i, 1, n) s[i]=s[i-1]+a[i];

	forint(i, 1, n) t[i]=MP(s[i], i-1);
	sort(t+1, t+n+1);
	forint(i, 1, n) swap(t[i].fi,t[i].se);


	//forint(i, 1, n) cout<<t[i].fi<<" "<<t[i].se<<endl;

	ans=1LL<<60;
	go(1, n);
	cout<<ans<<endl;
	//if(ans!=tmp) for(;;);
	//}


	return 0;
}