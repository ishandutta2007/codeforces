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

const int MAXS=1<<24;

int n; int c[55];
int _log[MAXS];
int s[MAXS], sn[MAXS];
bool ok[MAXS];

int main() {
	cin>>n; forn(i, n) cin>>c[i];
	sort(c, c+n);
	forn(i, n) _log[1<<i]=i;
	s[0]=sn[0]=0;
	int all=(1<<n)-1;
	forint(i, 1, all) {
		s[i]=s[i^(i&-i)]+c[_log[i&-i]];
		sn[i]=sn[i^(i&-i)]+1;
	}
	int cur=0, ci=0; while(ci<n && c[ci]==1) cur|=(1<<ci), ++ci;
	fillchar(ok, false);
	ok[cur]=true;
	forint(st, 1, all) if(ok[st]) {
		int i=n-1; while((st&(1<<i))==0) --i;
		++i; if(i>=n) continue;
		for(int s2=st; s2; s2=(s2-1)&st)
			if(s[s2]+1==c[i] && sn[s2]>=2)
				ok[(st^s2)^(1<<i)]=true;
	}
	printf("%s\n", ok[1<<(n-1)]?"YES":"NO");

	return 0;
}