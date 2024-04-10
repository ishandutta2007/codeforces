#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, a[150150];

map<ll, int> freq;
map<ll, set<int> > pos;
vector<pair<ll, ll> > resp;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		freq[a[i]]++;
		pos[a[i]].insert(i);
	}
	
	while(!freq.empty()) {
		pair<ll, int> p = *(freq.begin());
		if(p.second > 1) {
			ll x = p.first;
			pos[x].erase(pos[x].begin());
			int j = *(pos[x].begin());
			pos[x].erase(pos[x].begin());
			
			freq[2*x]++;
			pos[2*x].insert(j);
			
			freq[x] -= 2;
			if(freq[x] == 0)
				freq.erase(freq.begin());
		} else {
			freq.erase(freq.begin());
		}
	}
	
	for(pair<ll, set<int> > p : pos) {
		for(int x : p.second) {
			resp.push_back({x, p.first});
		}
	}
	
	sort(resp.begin(), resp.end());
	printf("%d\n", resp.size());
	for(pair<ll, ll> p : resp) {
		printf("%lld ", p.second);
	}
	
	return 0;
}