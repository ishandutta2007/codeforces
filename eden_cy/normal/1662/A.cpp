#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

int a[12];
void solve() {
	FOR(i,1,10) a[i]=0;
	int n;
	scanf("%d",&n);
	FOR(i,1,n) {
		int b,d;
		scanf("%d%d",&b,&d);
		a[d]=max(a[d],b);
	}
	int r=0;
	FOR(i,1,10) {
		if(a[i]==0) {
			puts("MOREPROBLEMS");
			return ;
		}
		r+=a[i];
	}
	printf("%d\n",r);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}