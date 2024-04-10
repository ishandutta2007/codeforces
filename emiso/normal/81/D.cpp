#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

pair<int, int> a[50];
int sum, n, m, sz, id;
vector<int> ans;

int main() {
	scanf("%d %d", &n, &m);
	for(int i=0; i<m; i++) {
		scanf("%d",&a[i].F);
		a[i].S = i + 1;
	} sort(a, a + m);

	if(n == 1) {
		printf("-1\n");
		return 0;
	}

	for(int i=0; i<m; i++) {
		a[i].F = min(a[i].F, n/2);
		sum += a[i].F;
	}

	int _12 = min(a[m-1].F, sum - a[m-1].F);
	//printf("%d\n", a[m-1].F);
	for(int i=0, id=m-2;i<_12;i++) {
		ans.push_back(a[m-1].S);
		ans.push_back(a[id].S);
		sz += 2;

		a[m-1].F--;
		a[id].F--;
		if(!a[id].F) id--;
	}

	id = 0;
	while(sz < n && id < m) {
		int prev = sz;
		while(!a[id].F && id < m) id++, prev = -1;
		if(id >= m) break;
		for(int i=0; i<ans.size(); i++) {
			if(ans[i] != a[id].S && ans[(i+1)%ans.size()] != a[id].S) {
				ans.insert(ans.begin()+i+1, a[id].S);
				a[id].F--;
				sz++;
			}
			if(!a[id].F) break;;
			if(sz == n) break;
		}
		if(prev == sz) id++;
	}

	if(id == m) {
		printf("-1\n");
		return 0;
	}

	for(int i : ans) {
		printf("%d ", i);
	}

	return 0;
}