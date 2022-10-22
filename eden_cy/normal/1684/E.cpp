#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int N=2e5+50;

map<int,int> cnt;
map<int,int> id;
int a[N];
pii b[N];
int pos[N];
void solve() {
	int n,K;
	scanf("%d%d",&n,&K);
	cnt.clear();
	FOR(i,1,n) scanf("%d",&a[i]),cnt[a[i]]++;
	int m=0;
	for(auto it: cnt) {
		++m;
		id[it.first]=m;
		b[m]=make_pair(it.second,m);
	}
	sort(b+1,b+m+1);
	FOR(i,1,m) pos[b[i].se]=i;
	int r=m-0;
	int s=0;
	int left=K;
	int c=0;
	int t=m;
	FOR(i,0,n-1) {
		if(cnt[i]) {
			int x=pos[id[i]];
			if(x<=s) {
				left+=b[x].first;
			} else {
				--t;
			}
			b[x].first=0;
		} else {
			++c;
		}
		if(c>K) break;
		while(s<m) {
			if(b[s+1].first<=left) {
				if(b[s+1].first) --t;
				left-=b[s+1].first;
				++s;
			} else break;
		}
//		if(i==2) cerr << t << endl;
		r=min(r,t);
	}
	printf("%d\n",r);
}
int main() {
	int T;
//	T=1;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
	return 0;
}
/*
1
4 1
0 2 4 5

*/