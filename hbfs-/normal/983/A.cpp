#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL p,q,k;

LL gcd(LL a, LL b) {return b==0 ? a : gcd(b, a%b);}

inline LL rd() {
	LL x=0,f=1;char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return x*f;
}

inline void solve() {
	p = rd(), q = rd(), k = rd();
	LL t = gcd(p, q);
	q /= t;
	while ((t=gcd(k, q)) != 1) {
		while (q%t == 0) q /= t;
	}
	puts(q==1 ? "Finite" : "Infinite");
}

int main() {
	for (int T=rd();T;T--) solve();
	return 0;
}