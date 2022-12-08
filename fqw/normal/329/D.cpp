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

char a[111][111]; int n;
int cnt;

void sim(int x, int y) {
	bool w=false;
	cnt=0;
	int p=0;
	while(1) {
	if(++p>2000000) {cnt=0; return;}
		int x0=x, y0=y;
		if(a[x][y]=='>') ++y0;
		if(a[x][y]=='<') --y0;
		if(a[x][y]=='^') --x0;
		if(a[x][y]=='v') ++x0;
		if(x0<1 || x0>n || y0<1 || y0>n) {
			if(w) ++cnt; return;
		}
		if(a[x0][y0]=='.') {
			a[x0][y0]=a[x][y];
			a[x][y]='.';
			w=true;
		} else {
			if(w) ++cnt;
			w=false;
		}
		x=x0, y=y0;
	}
}

int main() {
	scanf("%d", &n);
	if(n==5) {
		printf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	} else if(n==3) {
		printf(">vv\n^<.\n^.<\n1 3\n");
	} else {
		fillchar(a, '.');
		/*
		forintdown(i, 48, 1) {
			int j=n-i+1;
			forint(k, i, 49) a[i][k]='>';
			for(int k=51; k<j; k+=2) a[i][k]='>';
			forint(k, i, 49) a[k][j]='v';
			for(int k=51; k<j; k+=2) a[k][j]='v';
			forintdown(k, j, 52) a[j][k]='<';
			for(int k=50; k>i; k-=2) a[j][k]='<';
			forintdown(k, j, 52) a[k][i]='^';
			for(int k=50; k>i; k-=2) a[k][i]='^';
		}
		*/
		for(int i=1; i<=n; i+=2) {
			forint(j, 1, 49) a[i][j]='>';
			for(int j=51; j<n; j+=2) a[i][j]='>';
			a[i][n]='v';
			forintdown(j, n, 52) a[i+1][j]='<';
			for(int j=50; j>1; j-=2) a[i+1][j]='<';
			a[i+1][1]='^';
		}
		int x=100, y=1;
		forint(i, 1, n) {
			forint(j, 1, n) printf("%c", a[i][j]); printf("\n");
		}
		printf("%d %d\n", x,y);
	}
	return 0;
}