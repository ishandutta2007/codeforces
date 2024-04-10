#include <bits/stdc++.h>
using namespace std;

#define count count_cheat

struct P { // tuple / array of size 3
	int x, y, k, id;
	bool is_red() const {
		return k == -1;
	}
	bool operator <(const P& b) const {
		if(x == b.x) {
			
			return !is_red() && b.is_red(); // black first
		}
		return x < b.x;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int,int>> red(n);
	for(pair<int,int>& p : red) {
		cin >> p.first >> p.second;
	}
	int m;
	cin >> m;
	vector<pair<   pair<int,int>,  int >> black(m);
	for(auto& p : black) {
		cin >> p.first.first >> p.first.second >> p.second;
	}
	
	vector<int> count(black.size());
	
	vector<P> events;
	for(int i = 0; i < (int) red.size(); ++i) {
		auto& p = red[i];
		events.push_back(P{p.first, p.second, -1, i + 1});
	}
	for(int i = 0; i < (int) black.size(); ++i) {
		auto& p = black[i];
		events.push_back(P{p.first.first, p.first.second, p.second, i + 1}); // [1 ... m]
		count[i] = events.back().k;
		assert(count[i] >= 1);
	}
	
	vector<int> memo_count = count;
	
	sort(events.begin(), events.end());
	
	set<pair<int,int>> a; // black points on the left
	// (y, ID)
	
	vector<int> answer(red.size()); // from 0 to red.size()-1
	
	vector<bool> touched(max(red.size(), black.size()));
	
	for(const P& event : events) {
		assert(event.id >= 1 && event.id <= (int) touched.size());
		if(event.is_red()) {
			// sometimes print "NO" and exit
			auto it = a.lower_bound(make_pair(event.y, -2));
			if(it == a.end()) {
				//~ assert(false);
				cout << "NO\n";
				return 0;
			}
			int id_black = it->second; // 1...black.size
			answer[event.id-1] = id_black;
			--count[id_black-1];
			//~ assert(touched[id_black-1]);
			//~ assert(count[id_black-1] >= 0);
			if(count[id_black-1] == 0) {
				a.erase(it);
			}
		}
		else {
			// black
			a.insert({event.y, event.id});
			//~ assert(!touched[event.id-1]);
			//~ touched[event.id-1] = true;
			//~ assert(count[event.id-1] != 0);
		}
	}
	
	cout << "YES\n";
	for(int x : answer) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
	for(int id : answer) {
		assert(1 <= id && id <= (int) black.size());
		--id;
		--memo_count[id];
		assert(memo_count[id] >= 0);
	}
	//~ sort(answer.begin(), answer.end());
	//~ for(int i = 0; i < (int) answer.size() - 1; ++i) {
		//~ assert(answer[i] != answer[i+1]);
	//~ }
}