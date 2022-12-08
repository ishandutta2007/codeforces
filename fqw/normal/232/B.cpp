#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;

const LL modnum=(LL)1E9+7;

LL f[111][111*111];
LL C[111][111];
int n, k;
LL m;

LL p1[111], p2[111];
LL pow(LL a, LL b) {
	LL x=1;
	for(; b>0; b>>=1, a=(a*a)%modnum)
		if(b&1) x=(x*a)%modnum;
	return x;
}

int main() {
	cin>>n>>m>>k;
	for(int i=0; i<=n; ++i) C[i][0]=C[i][i]=1;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%modnum;
	LL cnt=m/n;
	for(int i=0; i<=n; ++i) {
		p1[i]=pow(C[n][i], cnt);
		p2[i]=pow(C[n][i], cnt+1);
	}
	memset(f, 0, sizeof(f));
	f[0][0]=1;
	for(int i=1; i<=n; ++i) {
		LL *p;
		if(m%n>=i) p=p2; else p=p1;
		//cout<<"cnt="<<cnt<<endl;
		for(int j=0; j<=(i-1)*n; ++j) {
			for(int cur=0; cur<=n; ++cur) {
				LL tmp=(f[i-1][j]*p[cur])%modnum;
				f[i][j+cur]=(f[i][j+cur]+tmp)%modnum;
			}
		}
	}
	LL ans=f[n][k];
	ans=(ans%modnum+modnum)%modnum;
	cout<<ans<<endl;
	return 0;
}