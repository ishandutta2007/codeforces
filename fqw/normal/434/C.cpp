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
typedef pair<double,double> PDD;

const int MAXN=220;
const int MAXNodes=220;
const int MAXL=222;
const int MAXV=510;
const LL MOD=LL(1e9)+7;

int m;
struct Num {
	int len, a[MAXL];
	void read() {
		scanf("%d", &len);
		forintdown(i, len, 1) scanf("%d", &a[i]);
	}
	void minus_one() {
		int i=1;
		while(a[i]==0) a[i]=m-1, ++i;
		--a[i];
		while(len>0 && a[len]==0) --len;
	}
	void println() {
		forintdown(i, len,1) printf("%d", a[i]); printf("\n");
	}
};

int trie[MAXNodes][22], val[MAXNodes], ncnt;
int limit;

int f[MAXL][MAXV][MAXNodes][2];

LL solve(Num n) {
	if(n.len==0) return 0;
	fillchar(f, 0);
	f[n.len][0][1][1]=1;
	forintdown(i, n.len, 1) {
		forint(v, 0, limit) forint(x, 1, ncnt) forint(op, 0, 1) {
			if(f[i][v][x][op]==0) continue;
			int le=(i==n.len?1:0);
			int ri=(op==1?n.a[i]:m-1);
			forint(j, le, ri) {
				int y=trie[x][j];
				int tv=v+val[y]; if(tv>limit) continue;
				int oq=((op==1 && j==ri)?1:0);
				(f[i-1][tv][y][oq]+=f[i][v][x][op]) %=MOD;
			}
		}
		if(i<n.len) {
			forint(j, 1, m-1) {
				int y=trie[1][j];
				int tv=val[y]; if(tv>limit) continue;
				(f[i-1][tv][y][0]+=1) %=MOD;
			}
		}
	}
	LL ans=0;
	forint(v, 0, limit) forint(x, 1, ncnt) forint(op, 0, 1)
		(ans+=f[0][v][x][op]) %=MOD;
	//n.println(); cout<<" -- "<<ans<<endl;
	return ans;
}

int main() {
	int n;
	static int cv[MAXN];
	static Num ca[MAXN];
	Num le, ri;
	scanf("%d%d%d", &n,&m,&limit);
	le.read();
	ri.read();
	forint(i, 1, n) {
		ca[i].read();
		scanf("%d", &cv[i]);
	}

	ncnt=1;
	fillchar(trie, 0); fillchar(val, 0);
	forint(i, 1, n) {
		int cur=1;
		forintdown(j, ca[i].len, 1) {
			int &nxt=trie[cur][ca[i].a[j]];
			if(nxt==0) nxt=++ncnt;
			cur=nxt;
		}
		val[cur]+=cv[i];
	}
	static int q[MAXNodes]; int ss=0, tt=0;
	static int sfx[MAXNodes];
	forn(j, m)
		if(trie[1][j]==0) trie[1][j]=1;
		else {
			++tt; q[tt]=trie[1][j];
			sfx[trie[1][j]]=1;
		}
	while(ss<tt) {
		int x=q[++ss];
		val[x]+=val[sfx[x]];
		forn(j, m) 
			if(trie[x][j]==0) trie[x][j]=trie[sfx[x]][j];
			else {
				++tt; q[tt]=trie[x][j];
				sfx[trie[x][j]]=trie[sfx[x]][j];
			}
	}

	//printf("le: "); le.println();
	//printf("ri: "); ri.println();
	//printf("---++++\n");
	LL ans=solve(ri);
	le.minus_one();
	//printf("---++++\n");
	ans=(ans-solve(le)+MOD)%MOD;
	cout<<ans<<endl;

	return 0;
}