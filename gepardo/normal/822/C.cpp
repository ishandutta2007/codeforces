#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <tuple>
#include <climits>

using namespace std;

struct Event {
	int time, how, who;

	Event() {
	}

	Event(int time, int how, int who)
		: time(time), how(how), who(who) {
	}

	inline tuple<int, int, int> toTuple() const  {
		return make_tuple(time, how, who);
	}

	inline friend bool operator<(const Event &a, const Event &b) {
		return a.toTuple() < b.toTuple();
	}
};

int main() {
	int n, x; cin >> n >> x;
	vector<int> costs(n);
	vector<int> lengths(n);
	vector<Event> events;
	for (int i = 0; i < n; i++) {
		int l, r; cin >> l >> r >> costs[i];
		lengths[i] = r - l + 1;
		events.emplace_back(l, -1, i);
		events.emplace_back(r, +1, i);
	}
	sort(events.begin(), events.end());
	map<int, int> best;
	int ans = INT_MAX;
	for (Event event : events) {
		if (event.how < 0) {
			int needLen = x - lengths[event.who];
			if (best.count(needLen)) {
				ans = min(ans, costs[event.who] + best[needLen]);
			}
		} else {
			int theLen = lengths[event.who], theCost = costs[event.who];
			if (best.count(theLen)) {
				best[theLen] = min(best[theLen], theCost);
			} else {
				best[theLen] = theCost;
			}
		}
	}
	if (ans == INT_MAX) {
		ans = -1;
	}
	cout << ans << endl;
	return 0;
}