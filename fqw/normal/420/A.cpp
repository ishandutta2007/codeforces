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

int main() {
	bool ok[999]; fillchar(ok, false);
	ok['A']=true;
	ok['H']=true;
	ok['I']=true;
	ok['M']=true;
	ok['O']=true;
	ok['T']=true;
	ok['U']=true;
	ok['V']=true;
	ok['W']=true;
	ok['X']=true;
	ok['Y']=true;
	static char s[199919];
	scanf("%s", s+1); int n=strlen(s+1);
	bool flag=true;
	for(int i=1, j=n; i<=j; ++i, --j)
		if(s[i]!=s[j] || !ok[s[i]])
			flag=false;
	printf("%s\n", flag?"YES":"NO");
	return 0;
}