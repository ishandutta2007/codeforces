#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct segment {
	int x, type, diametr, id;
};

bool cmp(segment &a, segment &b) {
	return (a.x < b.x || (a.x == b.x && a.type < b.type) || (a.x == b.x && a.type == b.type && a.diametr < b.diametr));
}

int main() {
	int n, k;
	cin >> n >> k;
	vector <pair <int, int>> answer;
	vector <segment> seg(2 * n);
	for (int i = 0; i < 2 * n; i += 2) {
		cin >> seg[i].x >> seg[i + 1].x;
		seg[i].type = 0;
		seg[i].diametr = seg[i + 1].x;
		seg[i + 1].diametr = seg[i].x;
		seg[i + 1].type = 1;
		seg[i].id = i / 2;
		seg[i + 1].id = i / 2;
	}
	sort(seg.begin(), seg.end(), cmp);
	int cnt = 0;
	set <pair <int, int>> prot;
	vector <int> donotuse (300000);
	for (int i = 0; i < 2 * n; i++) {
		if (seg[i].type == 0) {
			cnt++;
			prot.insert({ seg[i].diametr, seg[i].id });
			if (cnt > k) {
				pair <int, int> x = *prot.rbegin();
				answer.push_back(x);
				donotuse[x.second]++;
				prot.erase(x);
				cnt--;
			}
		}
		if (seg[i].type == 1) {
			if (donotuse[seg[i].id] != 0) {
				donotuse[seg[i].id]--;
				continue;
			}
			else
				cnt--;
		}
	}
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i].second + 1 << " ";
	return 0;
}