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

const int MAXN=55;

LL x1[MAXN], x2[MAXN], x12[MAXN], x21[MAXN], x22[MAXN];
bool s1[MAXN], e1[MAXN];

int n, _x, la, lb;
LL x;

PII getn(int len, int s, int t) {
	if(len==1) {
		if(s==t) return MP(0,0);
		return MP(1,0);
	}
	if(len==2) {
		if(s==1 && t==2) return MP(1,1);
		return MP(0,0);
	}
	PII ans;
	ans.fi=0;
	if(s==1) {
		ans.se=(len-1)/2;
		if(len%2==0 && t==2) ++ans.se;
	} else {
		ans.se=(len-2)/2;
		if(len%2==1 && t==2) ++ans.se;
	}
	return ans;
}

const char ch[3]={'X', 'A', 'C'};

void output(int len, int s, int t, int k) {
	//printf("out %d %d %d %d\n", len,s,t,k);
	if(len==1) {
		printf("%c\n", ch[s]); return;
	}
	if(len==2) {
		printf("%c%c\n", ch[s],ch[t]); return;
	}
	static char a[999];
	memset(a, 'X', sizeof(a));
	a[1]=ch[s], a[len]=ch[t];
	int st=(a[1]=='A'?1:2);
	forint(i, 1, k) {
		a[i*2-2+st]='A';
		a[i*2-1+st]='C';
	}
	a[len+1]='\0';
	printf("%s\n", a+1);
}

void solve() {
//printf("x1=%lld x2=%lld x12=%lld x21=%lld x22=%lld\n",x1[n],x2[n],x12[n],x21[n],x22[n]);
	forn(s1, 3) forn(t1, 3)
		forn(s2, 3) forn(t2, 3) {
			LL num=0;
			if(t1==1 && s2==2) num+=x12[n];
			if(t2==1 && s1==2) num+=x21[n];
			if(t2==1 && s2==2) num+=x22[n];
			PII na=getn(la, s1, t1);
			PII nb=getn(lb, s2, t2);
			forint(ia, na.fi, na.se) forint(ib, nb.fi, nb.se) {
				if(num+x1[n]*ia+x2[n]*ib==x) {
					output(la, s1, t1, ia);
					output(lb, s2, t2, ib);
					return;
				}
			}
		}
	printf("Happy new year!\n");
}

int main() {
	scanf("%d%d%d%d", &n,&_x,&la,&lb);
	x=_x;
	x1[1]=1, x2[1]=0, x12[1]=0, x21[1]=0, x22[1]=0;
	s1[1]=e1[1]=true;
	x1[2]=0, x2[2]=1, x12[2]=0, x21[2]=0, x22[2]=0;
	s1[2]=e1[2]=false;
	forint(i, 3, n) {
		x1[i]=x1[i-2]+x1[i-1];
		x2[i]=x2[i-2]+x2[i-1];
		s1[i]=s1[i-2], e1[i]=e1[i-1];
		x12[i]=x12[i-2]+x12[i-1]; if(e1[i-2] && !s1[i-1]) ++x12[i];
		x21[i]=x21[i-2]+x21[i-1]; if(!e1[i-2] && s1[i-1]) ++x21[i];
		x22[i]=x22[i-2]+x22[i-1]; if(!e1[i-2] && !s1[i-1]) ++x22[i];
	}
	solve();

	return 0;
}