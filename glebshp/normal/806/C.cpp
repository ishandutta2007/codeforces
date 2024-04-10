#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int size = 1000 * 1000 + 100;
const long long kMaxVal = 1000ll * 1000 * 1000 * 1000ll;
int n;
long long a[size];

bool check(int num, set <pair <long long, int> > nums) {
	vector <long long> can;

	for (int i = 0; i < num; i++) {
		long long cur = 1ll;
		while (true) {
			auto it = nums.lower_bound(mp(cur, -1));
			if (it == nums.end() || it->fs != cur) {
				break;
			} else {
				nums.erase(it);
				cur *= 2;
			}
		}

		can.pb(cur);
	}

	sort(can.rbegin(), can.rend());
	vector <long long> tocover;

	for (auto& e : nums) {
		tocover.pb(e.fs);
	}
	sort(tocover.rbegin(), tocover.rend());

	if (can.size() < tocover.size())
		return false;
	for (int i = 0; i < (int) tocover.size(); i++)
		if (tocover[i] > can[i])
			return false;

	return true;
}

int main () {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    	scanf("%lld", &a[i]);

    set <pair <long long, int> > nums;
    for (int i = 0; i < n; i++ ) {
    	nums.insert(mp(a[i], i));
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    	if (a[i] == 1ll)
    		cnt++;

   	if (!check(cnt, nums)) {
   		printf("-1\n");

   		return 0;
   	}

   	int lb = 1;
   	int rb = cnt;
   	while (lb < rb) {
   		int mid = (lb + rb) / 2;
   		if (check(mid, nums))
   			rb = mid;
   		else
   			lb = mid + 1;
   	}

   	for (int i = lb; i <= cnt; i++)
   		printf("%d%c", i, " \n"[i == cnt]);

    return 0;
}