#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

LL modnum;

struct Matrix {
	LL a[2][2];
	void mul(Matrix y) {
		Matrix x=*this;
		memset(a, 0, sizeof(a));
		for(int i=0; i<2; ++i)
			for(int j=0; j<2; ++j)
				for(int k=0; k<2; ++k)
					a[i][j]=(a[i][j]+x.a[i][k]*y.a[k][j])%modnum;
	}
};

LL fib(LL n) {
	Matrix a;
	a.a[0][0]=a.a[0][1]=a.a[1][0]=1, a.a[1][1]=0;
	Matrix t;
	t.a[0][0]=t.a[1][1]=1, t.a[1][0]=t.a[0][1]=0;
	--n;
	for(; n>0; n>>=1, a.mul(a))
		if(n&1) t.mul(a);
	LL ans=t.a[0][0];
	return (ans%modnum+modnum)%modnum;
}

LL nxt(LL n, LL x) {
	LL t=n/x+1;
	LL y=n/t;
	return min(x-1, y);
}

int main() {
	LL l, r, k;
	cin>>modnum>>l>>r>>k;
	LL x=(r-l)/(k-1);
	while(r/x-(l-1)/x<k)
		x=max(nxt(r,x), nxt(l-1,x));
	LL ans=fib(x);
	cout<<ans<<endl;
	return 0;
}