#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	LL pn = n, pm = m, pk = k;
	LL pnk = __gcd(pn, pk);
	pn /= pnk, pk /= pnk;
	LL pmk = __gcd(pm, pk);
	pm /= pmk, pk /= pmk;
	if(pk > 2) printf("NO");
	else if(pk == 2) printf("YES\n0 0\n%lld 0\n0 %lld", pn, pm);
	else if(pn * 2 <= n) printf("YES\n0 0\n%lld 0\n0 %lld", pn * 2, pm);
	else printf("YES\n0 0\n%lld 0\n0 %lld", pn, pm * 2);
}