#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}

namespace MCF {
	// required <string.h> <vector> <queue> <algorithm>
	#define MAXN 15400
	#define MAXM 3100000
	#define wint int
	#define cint long long
	const wint wEPS = 0;
	const wint wINF = 1001001001;
	const cint cEPS = 0;
	const cint cINF = 100100100100100100LL;
	int n, m, ptr[MAXN], next[MAXM], zu[MAXM];
	wint capa[MAXM], tof;
	cint cost[MAXM], toc, d[MAXN], pot[MAXN];
	int vis[MAXN], pree[MAXN];
	void init(int _n) {
		n = _n; m = 0; memset(ptr, ~0, n * 4);
	}
	void ae(int u, int v, wint w, cint c) {
		next[m] = ptr[u]; ptr[u] = m; zu[m] = v; capa[m] = w; cost[m] = +c; ++m;
		next[m] = ptr[v]; ptr[v] = m; zu[m] = u; capa[m] = 0; cost[m] = -c; ++m;
	}
	bool solve(int src, int ink, wint flo = wINF) {
		int i, u, v;
		wint f;
		cint c, cc;
		memset(pot, 0, n * sizeof(cint));
		//*
		for (bool cont = 1; cont; ) {
			cont = 0;
			for (u = 0; u < n; ++u) for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
				if (pot[zu[i]] > pot[u] + cost[i] + cEPS) {
					pot[zu[i]] = pot[u] + cost[i]; cont = 1;
				}
			}
		}
		//*/
		for (toc = 0, tof = 0; tof + wEPS < flo; ) {
			typedef pair<cint,int> node;
			priority_queue< node,vector<node>,greater<node> > q;
			for (u = 0; u < n; ++u) { d[u] = cINF; vis[u] = 0; }
			for (q.push(make_pair(d[src] = 0, src)); !q.empty(); ) {
				c = q.top().first; u = q.top().second; q.pop();
				if (vis[u]++) continue;
				for (i = ptr[u]; ~i; i = next[i]) if (capa[i] > wEPS) {
					cc = c + cost[i] + pot[u] - pot[v = zu[i]];
					if (d[v] > cc + cEPS) { q.push(make_pair(d[v] = cc, v)); pree[v] = i; }
				}
			}
			if (!vis[ink]) return 0;
			f = flo - tof;
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; f=min(f,capa[i]); }
			for (v = ink; v != src; v = zu[i ^ 1]) { i = pree[v]; capa[i] -= f; capa[i ^ 1] += f; }
			tof += f;
			toc += f * (d[ink] - pot[src] + pot[ink]);
			for (u = 0; u < n; ++u) pot[u] += d[u];
		}
		return 1;
	}
}
int big[60];
int x[60];
int y[60];
int main(){
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	for(int i=0;i<c;i++){
		int p;scanf("%d",&p);p--;
		big[p]++;
	}
	for(int i=0;i<b;i++){
		scanf("%d%d",x+i,y+i);x[i]--;y[i]--;
	}
	MCF::init(a*103+2);
	int S=a*103;
	int T=a*103+1;
	for(int i=0;i<103;i++){
		MCF::ae(i*a,T,50,i*d);
		if(i<102){
			for(int j=0;j<b;j++){
				for(int k=0;k<c;k++){
					MCF::ae(i*a+x[j],i*a+y[j]+a,1,e*(k*2+1));
					MCF::ae(i*a+y[j],i*a+x[j]+a,1,e*(k*2+1));
				}
			}
			for(int j=0;j<a;j++){
				MCF::ae(i*a+j,i*a+j+a,50,0);
			}
		}
	}
	for(int i=0;i<a;i++){
		MCF::ae(S,i,big[i],0);
	}
	MCF::solve(S,T,c);
	printf("%lld\n",MCF::toc);
}