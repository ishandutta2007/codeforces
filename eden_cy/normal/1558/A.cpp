#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

const int M=4e5+50;
int ans[M];
void solve() {
	int a,b;
	scanf("%d%d",&a,&b);
	int n=a+b;
	int x=n/2,y=n-x;
	int res=0;
	FOR(i,0,min(x,a)) {
		if(a-i<=y) {
			ans[++res]=a-i+min(x-i,b);
		}
	}
	swap(x,y);
	FOR(i,0,min(x,a)) {
		if(a-i<=y) {
			ans[++res]=a-i+min(x-i,b);
		}
	}
	sort(ans+1,ans+res+1);
	res=unique(ans+1,ans+res+1)-ans-1;
	printf("%d\n",res);
	FOR(i,1,res) printf("%d%c",ans[i]," \n"[i==res]);
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}