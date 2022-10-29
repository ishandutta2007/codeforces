#include <cstdio>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 100;
ll a[N], S, SD, LIMIT, MinSD;

int main() {
	int n; ll k; scanf("%d%lld", &n, &k);
	map<ll,ll> mymap;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		S += --a[i];
		for (int j = 1; j <= a[i]/j; ++j) {
			mymap[j+1] += a[i]/j - a[i]/(j+1);
			if (j < a[i]/j) ++mymap[a[i]/j+1];
		}
	}
	LIMIT = S + k + n;
	MinSD = SD = S + n; 
	while (SD - n) {
		ll D = mymap.begin()->first;
		SD -= mymap.begin()->second;
		if (D * SD <= LIMIT)
			MinSD = SD;
		mymap.erase(D);
	}
	printf("%lld", LIMIT / MinSD);
}