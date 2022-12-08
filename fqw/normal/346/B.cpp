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

const int MAXN=111;

char s1[MAXN], s2[MAXN], v[MAXN];
int l1, l2, lv;
int f[MAXN][MAXN][MAXN];
int p1[MAXN][MAXN][MAXN];
int p2[MAXN][MAXN][MAXN];
int pk[MAXN][MAXN][MAXN];
bool pc[MAXN][MAXN][MAXN];

void update(int i, int j, int k, int i0, int j0, int k0, bool c) {
	if(setmax(f[i][j][k], f[i0][j0][k0]+(int)c)) {
		p1[i][j][k]=i0;
		p2[i][j][k]=j0;
		pk[i][j][k]=k0;
		pc[i][j][k]=c;
	}
}

int nxt[MAXN];

int main() {
	scanf("%s%s%s", s1+1,s2+1,v+1);
	l1=strlen(s1+1);
	l2=strlen(s2+1);
	lv=strlen(v+1);
	nxt[0]=nxt[1]=0;
	for(int i=2, j=0; i<=lv; ++i) {
		while(j>0 && v[j+1]!=v[i]) j=nxt[j];
		if(v[j+1]==v[i]) ++j;
		nxt[i]=j;
	}
	memset(f, 200, sizeof(f));
	f[0][0][0]=0;
	forint(i, 0, l1) forint(j, 0, l2) forint(k, 0, lv-1) {
		if(f[i][j][k]<0) continue;
		if(i<l1) update(i+1,j,k, i,j,k, false);
		if(j<l2) update(i,j+1,k, i,j,k, false);
		if(i<l1 && j<l2 && s1[i+1]==s2[j+1]) {
			int k2=k;
			while(k2>0 && v[k2+1]!=s1[i+1]) k2=nxt[k2];
			if(v[k2+1]==s1[i+1]) ++k2;
			update(i+1,j+1, k2, i,j,k, true);
		}
	}
	int i=l1, j=l2, k=0;
	forint(t, 0, lv-1) if(f[i][j][t]>f[i][j][k]) k=t;
	if(f[i][j][k]<=0) printf("0\n");
	else {
		//printf("ans=%d\n", f[i][j][k]);
		char ans[MAXN]; int len=f[i][j][k];
		ans[len+1]='\0';
		while(len>0) {
		//printf("%d %d %d c=%d ch=%c len=%d\n",i,j,k,pc[i][j][k],s1[i],len);
			if(pc[i][j][k]) ans[len--]=s1[i];
			int i0=p1[i][j][k];
			int j0=p2[i][j][k];
			int k0=pk[i][j][k];
			i=i0, j=j0, k=k0;
		}
		printf("%s\n", ans+1);
	}
	return 0;
}