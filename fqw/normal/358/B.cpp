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

char buf[100010];
string s;
int n;

int main() {
	scanf("%d", &n); s="";
	forint(i, 1, n) {
		scanf("%s", buf);
		s+="<3"+string(buf);
	}
	s+="<3";
	scanf("%s", buf);
	int j=0;
	int len=strlen(buf);
	forn(i, len) {
		if(j<s.size() && s[j]==buf[i]) ++j;
	}
	if(j<s.size()) printf("no\n"); else printf("yes\n");

	return 0;
}