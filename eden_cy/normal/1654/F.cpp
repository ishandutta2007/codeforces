#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second

const int Mod=998244353;

ll Fast(ll x,int b) {
	ll t=1;
	for(; b; b>>=1,x=x*x%Mod) {
		if(b&1) t=t*x%Mod;
	}
	return t;
}
int gcd(int x,int y) {
	return y?gcd(y,x%y):x;
}

const int N=1e6+50;

char s[N];
int a[N];
int val[20][N];
int d;
bool cmp(int x,int y) {
	if(val[d-1][x]!=val[d-1][y]) return val[d-1][x]<val[d-1][y];
	return val[d-1][x^(1<<(d-1))]<val[d-1][y^(1<<(d-1))];
}
int main() {
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	FOR(i,0,(1<<n)-1) val[0][i]=s[i]-'a';
	int p=0;
	FOR(i,1,n) {
		FOR(j,0,(1<<n)-1) a[j]=j;
		d=i;
		sort(a,a+(1<<n),cmp);
		int c=-1;
		FOR(j,0,(1<<n)-1) {
			if(!j || cmp(a[j-1],a[j])) ++c;
			val[i][a[j]]=c;
		}
		p=a[0];
	}
//	cerr << p << endl;
	FOR(i,0,(1<<n)-1) putchar(s[i^p]);
	putchar('\n');
	return 0;
}