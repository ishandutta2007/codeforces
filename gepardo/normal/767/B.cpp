#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int EVENT_OPEN = +1;
const int EVENT_CLOSE = -1;

int main() {
	ios_base::sync_with_stdio(false);
	int64_t tS, tF, t; cin >> tS >> tF >> t;
	int n; cin >> n;
	vector< pair<int64_t, int64_t> > v;
	set<int64_t> importantTimes;
	importantTimes.insert(0);
	importantTimes.insert(tS);
	importantTimes.insert(tF-1);
	
	multiset<int64_t> ends;
	for (int i = 0; i < n; i++) {
		int64_t time; cin >> time;
		while (!ends.empty() && *ends.begin() <= time) {
			ends.erase(ends.begin());
		}
		int64_t serviceTime = max(tS, time) + t;
		if (!ends.empty()) {
			serviceTime = max(serviceTime, *ends.rbegin() + t);
		}
		v.emplace_back(time, serviceTime);
		ends.insert(serviceTime);
		importantTimes.insert(time-1);		
		importantTimes.insert(time);
		importantTimes.insert(serviceTime);
	}
	int ktr = 0;
	int64_t bestAns = 1234569012345678LL;
	int64_t bestTime = 0;
	ends.clear();
	for (int64_t time: importantTimes) {
		while (ktr < n && v[ktr].first <= time) {
			ends.insert(v[ktr].second);
			ktr++;
		}
		while (!ends.empty() && *ends.begin() <= time) {
			ends.erase(ends.begin());
		}
		int64_t serviceTime = max(tS, time) + t;
		if (!ends.empty()) {
			serviceTime = max(serviceTime, *ends.rbegin() + t);
		}
		if (serviceTime <= tF) {
			int64_t curAns = serviceTime - time;
			if (curAns < bestAns) {
				bestAns = curAns;
				bestTime = time;
			}
		}
	}
	cout << bestTime << endl;
	return 0;
}