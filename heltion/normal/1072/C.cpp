#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
vector<LL> va, vb;
int main(){
	LL a, b, s = 0, t = 0;
	scanf("%lld %lld", &a, &b);
	while(s + (t + 1) <= a + b) s += ++t;
	for(LL i = t; i; i -= 1)
		if(b >= i){
			vb.push_back(i);
			b -= i;
		}
		else va.push_back(i);
	printf("%d\n", (int)va.size());
	for(LL x : va) printf("%lld ", x);
	printf("\n%d\n", (int)vb.size());
	for(LL x : vb) printf("%lld ", x);
}