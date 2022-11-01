#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, sum, tgt;
vector<int> resp;

int main() {
	scanf("%lld", &n);
	sum = n * (n+1) / 2;
	tgt = sum / 2;
	
	for(int i = n; i > 0; i--) {
		if(tgt >= i) {
			tgt -= i;
			resp.push_back(i);
		}
	}
	
	tgt = 0;
	for(int x : resp) tgt += x;
	
	printf("%lld\n", sum - 2*tgt);
	printf("%d", resp.size());
	for(int x : resp) printf(" %d", x);
	
	return 0;
}