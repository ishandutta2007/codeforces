#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=2010;
const LL MODNUM=(LL)1E9+7;

int a[MAXN];
int n, rounds;

LL inverse(LL x) {
	LL ans=1, p=MODNUM-2;
	for(; p>0; p>>=1, x=(x*x)%MODNUM)
		if(p&1) ans=(ans*x)%MODNUM;
	return ans;
}

LL inv[MAXN];
LL p[MAXN];
LL ans[MAXN];

int main() {
	scanf("%d%d", &n,&rounds);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i) inv[i]=inverse(i);
	p[1]=1;
	for(int i=2; i<=n; ++i)
		p[i]=p[i-1]*(rounds+i-2)%MODNUM*inv[i-1]%MODNUM;
	//for(int i=1; i<=n; ++i) cout<<"p["<<i<<"]="<<p[i]<<endl;
	memset(ans, 0, sizeof(ans));
	for(int i=1; i<=n; ++i)
		for(int j=i; j<=n; ++j)
			ans[j]=(ans[j]+(LL)a[i]*p[j-i+1])%MODNUM;
	for(int i=1; i<=n; ++i)
		printf("%d%c", (int)((ans[i]%MODNUM+MODNUM)%MODNUM), i<n?' ':'\n');
	return 0;
}