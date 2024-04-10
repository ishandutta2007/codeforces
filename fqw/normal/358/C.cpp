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

int a[100010];
bool c[100010];
int n;

int main() {
	scanf("%d", &n);
	set<PII> box;
	fillchar(c, false);
	forint(i, 1, n) {
		scanf("%d", &a[i]);
		if(a[i]==0) {
			forn(k, 3) {
				if(box.size()==0) break;
				PII p=*box.begin();
				box.erase(box.begin());
				c[p.se]=true;
			}
			box.clear();
		} else box.insert(MP(-a[i],i));
	}
	int ns=0, nq=0, nd=0;
	forint(i, 1, n)
		if(a[i]==0) {
			vector<string> ans;
			if(ns>0) --ns, ans.PB("popStack");
			if(nq>0) --nq, ans.PB("popQueue");
			if(nd>0) --nd, ans.PB("popBack");
			printf("%d", ans.size());
			forn(j, ans.size()) printf(" %s", ans[j].c_str());
			printf("\n");
		} else {
			if(c[i]) {
				string ans="pushStack"; int *ansn=&ns;
				if(nq<*ansn) ansn=&nq, ans="pushQueue";
				if(nd<*ansn) ansn=&nd, ans="pushBack";
				++*ansn; printf("%s\n", ans.c_str());
			} else
				printf("pushFront\n");
		}

	return 0;
}