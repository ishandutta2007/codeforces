#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//~ #define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

const int ADD = 0;
const int GET = 1;

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; int64_t p; cin >> n >> p;
	vector<int64_t> t(n);
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	set< tuple<int64_t, int, int> > events;
	set<int> waiting;
	set<int> notOnPlace;
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		events.emplace(t[i], ADD, i);
	}
	int served = 0;
	vector<int64_t> ans(n);
	while (served != n) {
		assert(!events.empty());
		auto [time, type, who] = *events.begin();
		//~ cout << time << " " << (type == ADD ? "ADD" : "GET") << " " << who << endl;
		events.erase(events.begin());
		if (type == ADD) {
			if (q.empty()) {
				q.push(who);
				notOnPlace.insert(who);
				events.emplace(time + p, GET, who);
			} else if (notOnPlace.empty() || *notOnPlace.begin() > who) {
				q.push(who);
				notOnPlace.insert(who);
			} else {
				waiting.insert(who);
			}
		} else if (type == GET) {
			assert(who == q.front());
			ans[who] = time;
			++served;
			q.pop();
			notOnPlace.erase(who);
			if (!waiting.empty() && (notOnPlace.empty() || *notOnPlace.begin() > *waiting.begin())) {
				int ww = *waiting.begin();
				waiting.erase(waiting.begin());
				q.push(ww);
				notOnPlace.insert(ww);
			}
			if (!q.empty()) {
				events.emplace(time + p, GET, q.front());
			}
		}
		
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}