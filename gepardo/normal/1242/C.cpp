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
#define int int64_t

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

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	int64_t soom = 0;
	map<int, int> mp;
	vector< vector<int> > box(n);
	vector<int64_t> sbox(n);
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		vector<int> bx(k);
		for (int &j : bx) {
			cin >> j;
			mp[j] = i;
			sbox[i] += j;
		}
		box[i] = bx;
		soom += sbox[i];
	}
	
	if (soom % n != 0) {
		cout << "No" << endl;
		return 0;
	}
	int64_t one = soom / n;
	
	vector<char> can(1 << n, false);
	vector< vector< pair<int, int> > > how(1 << n);
	for (int i = 0; i < n; ++i) {
		for (int b : box[i]) {
			vector< pair<int, int> > did;
			int msk = 0;
			int v = i, carry = b;
			while (true) {
				msk |= 1 << v;
				int64_t now = one - sbox[v] + carry;
				if (now == b) {
					did.emplace_back(b, v);
					can[msk] = true;
					how[msk] = did;
					break;
				}
				int nxt = mp.count(now) ? mp[now] : -1;
				if (nxt < 0 || ((msk >> nxt) & 1)) break;
				did.emplace_back(now, v);
				carry = now;
				v = nxt;
			}
		}
	}
	
	vector<int> dp(1 << n, -1);
	dp[0] = 0;
	for (int i = 1; i < (1 << n); ++i) {
		for (int smask = i; smask != 0; --smask, smask &= i) {
			int sub = i ^ smask;
			if (dp[sub] >= 0 && can[smask]) {
				dp[i] = smask;
				break;
			}
		}
	}
	
	if (dp.back() < 0) {
		cout << "No\n";
		return 0;
	}
	
	int v = (1 << n) - 1;
	vector< pair<int, int> > ans(n, make_pair(-1, -2));
	while (v != 0) {
		assert(dp[v] >= 0);
		for (auto [val, to] : how[dp[v]]) {
			ans[mp[val]] = {val, to};
		}
		v ^= dp[v];
	}
	
	cout << "Yes\n";
	for (int i = 0; i < n; ++i) {
		cout << ans[i].first << " " << ans[i].second+1 << endl;
	}
	
	return 0;
}