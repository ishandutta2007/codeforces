#include<cstdio>
#include<vector>
#include<algorithm>
#define maxn 300000
long long x[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i += 1) scanf("%lld", x + i);
	std::sort(x, x + n);
	std::vector<long long> twans;
	std::vector<long long> thans;
	for(int i = 0; i < n; i += 1){
		for(long long d = 1;; d <<= 1){
			int pos = std::lower_bound(x + i, x + n, x[i] + d) - x;
			if(pos == n) break;
			if(x[pos] == x[i] + d){
				if(twans.empty()) twans.push_back(x[i]), twans.push_back(x[i] + d);
				pos = std::lower_bound(x + i, x + n, x[i] + 2 * d) - x;
				if(pos < n and x[pos] == x[i] + 2 * d)
				if(thans.empty()) thans.push_back(x[i]), thans.push_back(x[i] + d),
					thans.push_back(x[i] + 2 * d);
			}
		}
	}
	if(thans.size()) printf("3\n%lld %lld %lld", thans[0], thans[1], thans[2]);
	else if(twans.size()) printf("2\n%lld %lld", twans[0], twans[1]);
	else printf("1\n%lld", x[0]);
}