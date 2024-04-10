#include<stdio.h>
#include<map>
using namespace std;
int n, k;
int a[100100];
std::map<long long int, int> mp;
long long int ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long int p;
	p = 0;
	mp[p]++;
	for (int i = 0; i < n; i++) {
		p += a[i];
		long long int l = 1;
		while (l < 1e15&&l >(-(1e15))) {
			ans += mp[p - l];
			l *= k;
			if (l == 1)break;
		}
		mp[p]++;
	}
	printf("%I64d", ans);
	return 0;
}