#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_e"

const double pi = acos(-1.0);
const int size = 1000 * 1000 + 100;
const int inf = 1000 * 1000 * 1000 * 2 + 1000;

long long p[size], len[size];
int n, q;
long long ans[size];
vector <pair <int, int> > nums[size];

int main() {
//	assert(freopen("input.txt", "r", stdin));
//	assert(freopen("output.txt", "w", stdout));
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d%I64d", &p[i], &len[i]);

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int lft, rgt;
		scanf("%d%d", &lft, &rgt);
		lft--, rgt--;

		nums[lft].pb(mp(rgt, i));
	}

	vector <pair <long long, long long> > freespace;
	vector <long long> sum;

	for (int i = n - 1; i >= 0; i--) {
		if (i < n - 1) {
			freespace.pb(mp(p[i], p[i + 1]));
			if (sum.empty())
				sum.pb(freespace.back().sc - freespace.back().fs);
			else
				sum.pb(sum.back() + freespace.back().sc - freespace.back().fs);

			while (!freespace.empty() && freespace.back().sc <= p[i] + len[i]) {
				freespace.pop_back();
				sum.pop_back();
			}
			if (!freespace.empty() && freespace.back().fs < p[i] + len[i]) {
				long long d = p[i] + len[i] - freespace.back().fs;
				freespace.back().fs += d;
				sum.back() -= d;
			}
		}
		for (int j = 0; j < (int) nums[i].size(); j++) {
			if (sum.empty()) {
				ans[nums[i][j].sc] = 0;
			} else {
				ans[nums[i][j].sc] = sum.back();
				if (freespace[0].sc > p[nums[i][j].fs]) {
					int lb = 0;
					int rb = (int) freespace.size() - 1;
					while (lb < rb) {
						int mid = (lb + rb + 1) / 2;
						if (freespace[mid].sc > p[nums[i][j].fs])
							lb = mid;
						else
							rb = mid - 1;
					}

					ans[nums[i][j].sc] -= sum[lb];
				}
			}
		}
	}

	for (int i = 0; i < q; i++)
		printf("%I64d\n", ans[i]);

	return 0;
}