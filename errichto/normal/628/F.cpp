// Bear and Fair Set, by Errichto
#include<bits/stdc++.h>
using namespace std;
 
const int K = 5;
 
void NO() {
	puts("unfair");
	exit(0);
}
 
int main() {
	int n, b, q;
	scanf("%d%d%d", &n, &b, &q);
	vector<pair<int,int>> w;
	w.push_back(make_pair(b, n));
	while(q--) {
		int a, b;
		scanf("%d%d", &a, &b);
		w.push_back(make_pair(a, b));
	}
	sort(w.begin(), w.end());
	// use the Hall's theorem
	// check all 2^K sets of remainders
	for(int mask = 0; mask < (1 << K); ++mask) {
		int at_least = 0, at_most = 0;
 
		int prev_upto = 0, prev_quan = 0;
		for(pair<int,int> query : w) {
			int now_upto = query.first, now_quan = query.second;
			int places_matching = 0; // how many do give remainder from "mask"
			int places_other = 0;
			for(int i = prev_upto + 1; i <= now_upto; ++i) {
				if(mask & (1 << (i % K)))
					++places_matching;
				else
					++places_other;
			}
			if(now_quan < prev_quan) NO();
			int quan = now_quan - prev_quan;
			int places_total = now_upto - prev_upto;
			assert(places_total == places_matching + places_other);
			if(quan > places_total) NO();
 
			at_least += max(0, quan - places_other);
			at_most += min(quan, places_matching);
 
			prev_upto = now_upto;
			prev_quan = now_quan;
		}
 
		// "mask" represents a set of popcount(mask) remainders
		// their total degree is (n/K)*popcount(mask)
		int must_be = n / K * __builtin_popcount(mask);
		if(at_most < must_be) {
		    NO();
		}
		//if(!(at_least <= must_be && must_be <= at_most)) NO();
	}
	puts("fair");		
	return 0;
}