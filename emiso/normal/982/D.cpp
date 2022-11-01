#include <bits/stdc++.h>

#define MN 100010

using namespace std;

int n, a[MN], k, in[MN], num, best, ans;
vector<pair<int, int> > ys;

int pai[MN], sz[MN];
map<int, int> freq;

void upd(int x, int delta) {
	freq[x] += delta;
	if(freq[x] <= 0) freq.erase(x);
}

int find(int x) {
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(sz[a] > sz[b]) {
		pai[b] = a;
		
		upd(sz[a], -1);
		upd(sz[b], -1);
		sz[a] += sz[b];
		upd(sz[a], 1);
	}
	else {
		pai[a] = b;
		
		upd(sz[a], -1);
		upd(sz[b], -1);
		sz[b] += sz[a];
		upd(sz[b], 1);
	}
	return true;
}

int main() {
	scanf("%d", &n);
	
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		
		ys.push_back({a[i], i});
	}
	
	sort(ys.begin(), ys.end());
	for(auto p : ys) {
		int val = p.first;
		int id = p.second;
		
		pai[id] = id;
		sz[id] = 1;
		upd(1, 1);
		
		if(in[id-1] && in[id+1]) {
			merge(id-1, id);
			merge(id, id+1);
			num--;
		}
		
		else if(in[id-1]) {
			merge(id-1, id);
		}
		
		else if(in[id+1]) {
			merge(id, id+1);
		}
		
		else {
			num++;
		}
		
		if(freq.size() == 1) {
			if(num > best) {
				best = num;
				ans = val + 1;
			}
		}
		
		in[id] = 1;
	}
	
	printf("%d\n", ans);

	return 0;
}