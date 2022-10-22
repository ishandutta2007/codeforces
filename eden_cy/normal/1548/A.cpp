#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
const int M=2e5+50;

int cnt[M];

int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	int res=n;
	int q;
	FOR(i,1,m) {
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		if(cnt[x]==0) --res;
		++cnt[x];
	}
	scanf("%d",&q);
	FOR(i,1,q) {
		int op,x,y;
		scanf("%d",&op);
		if(op==1) {
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			if(cnt[x]==0) --res;
			++cnt[x];
		} else if(op==2) {
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			--cnt[x];
			if(cnt[x]==0) ++res;
		} else {
			printf("%d\n",res);
		}
	}
	return 0;
}