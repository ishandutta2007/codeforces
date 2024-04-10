#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
const int N=1e6+50;
int co[N];
char s[N];
int cnt[N];
void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s);
	int r1=0,r2=0;
	int u=0;
	FOR(i,0,m-1) co[i]=cnt[i]=0;
	FOR(i,0,n*m-1) {
		int c=s[i]-'0';
		if(c) {
			if(co[i%m]==0) ++r1;
			++co[i%m];
		}
		if(i>=m) {
			if(s[i-m]=='1') --u;
		}
		if(c) ++u;
		cnt[i%m]+=(u>0);
		r2=cnt[i%m];
		printf("%d%c",r1+r2," \n"[i==n*m-1]);
	}
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}