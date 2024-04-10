#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n;
int a[1600];
vector< pair<int, pair<int, int> > > sums;

int main() {
	scanf("%d", &n);
	REP(i,n) scanf("%d", &a[i]);

	for (int i = 0; i < n; i++) {
		int s = 0;
		for (int j = i; j < n; j++) {
			s += a[j];
			sums.push_back({s, {j, i}});
		}
	}

	sums.push_back({1000000000, {-1, -1}});
	sort(sums.begin(), sums.end());

	int la = -1;
	pii cur;
	int b = 0;
	int bc = -1;
	int c = -1;
	
	for (auto p : sums) {
		if (la != p.first) {
			if (bc < c) {
				bc = c;
				b = la;
			}

			la = p.first;
			cur = {-1, -1};
			c = 0;
		}

		if (cur.first < p.second.second) {
			cur = p.second;
			c++;
		}
	}

	printf("%d\n", bc);
	cur = {-1, -1};

	for (auto p : sums) if (p.first == b) {
		if (p.second.second > cur.first) {
			cur = p.second;
			printf("%d %d\n", cur.second+1, cur.first+1);
		}
	}
}