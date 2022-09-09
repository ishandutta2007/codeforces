#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
auto no = [](){cout << "NO"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 100
LL p[maxn], r[maxn], pn;
LL gget(LL n, LL p){
	if(n < p) return 0;
	return n / p + gget(n / p, p) + gget(n % p, p);
}
int main(){
	ios::sync_with_stdio(false);
	LL n, b;
	cin >> n >> b;
	while(b != 1){
		LL x = 0;
		for(LL i = 2; i * i <= b; i += 1) if(b % i == 0) {
			x = i;
			break;
		}
		if(x){
			p[pn] = x;
			while(b % x == 0){
				b /= x;
				r[pn] += 1;
			}
		}
		else{
			p[pn] = b;
			b = r[pn] = 1;
		}
		pn += 1;
	}
	LL ans = 1E18;
	for(int i = 0; i < pn; i += 1){
		ans = min(ans, gget(n, p[i]) / r[i]);
	}
	cout << ans;
}