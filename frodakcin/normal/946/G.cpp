#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 202000;
const int lmaxn = 20;
const int inf = 1010000000;

int n, aoriginal[maxn], a[maxn];
vector<int> compress;

int bsearch(int g) {
	int low = -1, high = compress.size();
	
	while(high > low+1) {
		int mid = (low+high)/2;
		if(compress[mid] < g) {
			low = mid;
		} else {
			high = mid;
		}
	}
	
	return high;
}

int BIT[maxn * 3], BITR[maxn * 3];
int rbc;
int rbstates[maxn];

int * val[maxn*2*lmaxn];
int to[maxn*2*lmaxn];

int queryR(int v) {			//everything larger than n
	v = n * 3 - v  + 3;
	
	int ret = -1;
	for(int i = v;i > 0;i -= (i&(-i))) {
		
		if(BITR[i] > ret) {
			ret = BITR[i];
		}
		
	}
	
	return ret;
	
}

void updateR(int v, int mx) {
	v = n * 3- v  + 3;
	
	for(int i = v;i <= (n * 3 + 2);i += (i&(-i))) {
		
		if(mx > BITR[i]) {
			val[rbc] = &BITR[i];
			to[rbc] = BITR[i];
			
			BITR[i] = mx;
			rbc++;
		}
		
	}
}

void rollback(int ns) {
	
	while(rbc > ns) {
		rbc--;
		*(val[rbc]) = to[rbc];
	}
	
}

int query(int v) {
	
	int ret = -1;
	for(int i = v;i > 0;i -= (i&(-i))) {
		
		if(BIT[i] > ret) {
			ret = BIT[i];
		}
		
	}
	
	return ret;
	
}
void update(int v, int mx) {
	
	for(int i = v;i <= (n * 3 + 2);i += (i&(-i))) {
		
		if(mx > BIT[i]) {
			BIT[i] = mx;
		}
		
	}
}

int main() {
	
	scanf("%d", &n);
	for(int i = 0;i < n;i++) {
		scanf("%d", &aoriginal[i]);
		aoriginal[i] -= i;
		compress.push_back(aoriginal[i]);
		compress.push_back(aoriginal[i] + 1);
		compress.push_back(aoriginal[i] - 1);
	}
	compress.push_back(inf);
	compress.push_back(-inf);
	
	sort(compress.begin(), compress.end());
	compress.resize(distance(compress.begin(), unique(compress.begin(), compress.end())));
	
	rbc = 0;
	for(int i = 0;i <= n * 3;i++) {
		BITR[i] = 0;
	}
	rbstates[n] = 0;
	for(int i = n-1;i >= 0;i--) {
		rbstates[i] = rbc;
		
		int v = bsearch(aoriginal[i]);
		
		updateR(v, queryR(v) + 1);
	}
	
	for(int i = 0;i <= n * 3;i++) {
		BIT[i] = 0;
	}
	int ans = 0;
	for(int i = 0;i < n;i++) {
		rollback(rbstates[i]);
		
		int npans = -1;
		
		if(i >= 1 && i < n-1) {
			
			npans = max(query(bsearch(aoriginal[i-1])) + queryR(bsearch(aoriginal[i-1] - 1)), query(bsearch(aoriginal[i+1] + 1)) + queryR(bsearch(aoriginal[i+1])));
			
		}
		
		if(i == 0) {
			npans = queryR(bsearch(aoriginal[i+1]));
		}
		if(i == n-1) {
			npans = query(bsearch(aoriginal[i-1]));
		}
		
		if (npans > ans) {
			ans = npans;
		}
		
		int v = bsearch(aoriginal[i]);
		update(v, query(v) + 1);
	}
	
	
	printf("%d\n", (n-1) - ans);
	
	return 0;
}