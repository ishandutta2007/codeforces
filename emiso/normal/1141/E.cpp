
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll h, n, d[200020], mini, tmp, idx, ans;

int main() {
	scanf("%lld %lld", &h, &n);
	
	for(int i = 0; i < n; i++) {
		scanf("%lld", &d[i]);
		tmp += d[i];
		
		if(tmp < mini) {
			mini = tmp;
			idx = i + 1;
		}
		
		if(-tmp >= h) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	
	if(tmp >= 0) {
		printf("-1\n");
		return 0;
	}
	
	ans += (h + mini) / -tmp * n;
	h += (h + mini) / -tmp * tmp;
	
	while(h > 0)
		for(int i = 0; h > 0 && i < n; i++, ans++)
			h += d[i];
			
	printf("%lld\n", ans);
	return 0;
}