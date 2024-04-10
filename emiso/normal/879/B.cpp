#include <bits/stdc++.h>
#define MN 100010

using namespace std;
typedef long long ll;

int n, a;
ll k;

deque<int> p;

int main() {			
	scanf("%d %lld", &n, &k);
	if(k > n) k = n;
	
	for(int i = 0; i < n; i++) {
		scanf("%d", &a);
		p.push_back(a);
	}
	
	int row = 0, last = -1;
	while(row < k) {
		int u = p.front(); p.pop_front();
		int v = p.front(); p.pop_front();
		
		if(u > v) {
			if(last != u) {
				last = u;
				row = 0;
			}
			if(last == u) row++;
			p.push_front(u);
			p.push_back(v);
		}
		
		else {
			if(last != v) {
				last = v;
				row = 0;
			}
			if(last == v) row++;
			p.push_front(v);
			p.push_back(u);
		}
	}
	
	printf("%d\n", last);
	return 0;
}