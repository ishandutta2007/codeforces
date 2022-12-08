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
typedef pair<LL,int> PLI;
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

const int MAXN=100010;

LL len[MAXN];
int op[MAXN], c[MAXN], l[MAXN];
int n;
int ans[MAXN];
set<PLI> box;

int main() {
	int q; scanf("%d", &q);
	len[0]=0;
	forint(i, 1, q) {
		scanf("%d", &op[i]);
		if(op[i]==1) {
			scanf("%d", &c[i]);
			len[i]=len[i-1]+1;
		} else {
			scanf("%d%d", &l[i],&c[i]);
			len[i]=len[i-1]+(LL)l[i]*(LL)c[i];
		}
	}
	box.clear();
	int n; scanf("%d", &n);
	forint(i, 1, n) {
		LL tmp; cin>>tmp;
		box.insert(MP(tmp, i));
	}
	fillchar(ans, 0xff);
	forintdown(i, q, 1) {
	//printf("i=%d\n",i);
		if(box.size()==0) break;
		if(op[i]==1) {
			while(box.size()>0) {
				set<PLI>::iterator it=--box.end();
				if(it->first==len[i]) {
					ans[it->second]=c[i];
					box.erase(it);
				} else break;
			}
		} else {
			vector<PLI> b;
			set<PLI>::iterator it=box.lower_bound(MP(len[i-1]+1, 0));
			for(; it!=box.end(); ++it) {
			//printf("b=(%lld,%d)\n",it->first,it->second);
				PLI cur=*it;
				cur.first-=len[i-1];
				cur.first=(cur.first-1)%l[i]+1;
				b.PB(cur);
			}
			//printf("here!\n");
			while(box.size()>0 && box.rbegin()->first>len[i-1])
				box.erase(--box.end());
			forn(j, b.size()) box.insert(b[j]);
		}
	}
	forint(i, 1, n) printf("%d%c", ans[i], i<n?' ':'\n');
	return 0;
}