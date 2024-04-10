#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)

typedef long long ll;

const int N=1e6+50;

char a[N];
int b[N];
int n;
int f(int x,int y) {
	return x==-1?1:x==y;
}
ll solve() {
	if(n==1) {
		if(b[n]==0 || b[n]==-1) return 1;
		else return 0;
	}
	if(b[1]==0) return 0;
	ll t=1;
	FOR(i,2,n-2) {
		if(b[i]==-1) t*=10;
	}
	int r=0;
	if(f(b[n-1],0) && f(b[n],0)) ++r;
	if(f(b[n-1],2) && f(b[n],5)) ++r;
	if(f(b[n-1],5) && f(b[n],0)) ++r;
	if(f(b[n-1],7) && f(b[n],5)) ++r;
	return t*r;
}
int main() {
	scanf("%s",a+1);
	n=strlen(a+1);
	int cx=0;
	FOR(i,1,n) {
		if(a[i]=='X') ++cx;
		else if(a[i]=='_') b[i]=-1;
		else b[i]=a[i]-'0';
	}
	ll res=0;
	if(cx) {
		FOR(j,0,9) {
			FOR(i,1,n) if(a[i]=='X') b[i]=j;
			if(b[1]==-1) {
				FOR(k,0,9) {
					b[1]=k;
					res+=solve();
				}
				b[1]=-1;
			} else {
				res+=solve();
			}
		}
	} else {
		if(b[1]==-1) {
			FOR(j,0,9) {
				b[1]=j;
				res+=solve();
			}
			b[1]=-1;
		} else {
			res+=solve();
		}
	}
	printf("%lld\n",res);
	return 0;
}