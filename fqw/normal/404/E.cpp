// 17:05 - 17:11 - pass sample
#include <iostream>
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

const int MAXN=1001000;

char s[MAXN]; int n;

bool init_check() {
	static int p[MAXN];
	p[0]=0;
	int l=0, r=0;
	forint(i, 1, n) {
		p[i]=p[i-1];
		if(s[i]=='L') --p[i]; else ++p[i];
		if(i==n) return p[i]<l || p[i]>r;
		l=min(l, p[i]);
		r=max(r, p[i]);
	}
	return false;
}

bool check(int bound) {
	if(bound==0) return true;
	int p=0;
	int l=0;
	forint(i, 1, n) {
		if(s[i]=='L') --p; else if(p+1<bound) ++p;
		if(i==n) return p<l;
		l=min(l, p);
	}
	return false;
}

int cal() {
	int le=0, ri=n;
	while(le<ri) {
		int mid=(le+ri+1)/2;
		if(check(mid)) le=mid;
			else ri=mid-1;
	}
	return le;
}

int main() {
	scanf("%s", s+1); n=strlen(s+1);
	if(init_check()) printf("1\n");
	else {
		int ans=cal();
		forint(i, 1, n) if(s[i]=='L') s[i]='R'; else s[i]='L';
		ans+=cal();
		printf("%d\n", ans);
	}
	return 0;
}