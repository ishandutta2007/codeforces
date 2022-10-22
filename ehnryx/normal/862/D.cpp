#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

//#define DEBUG
//#define USE_MAGIC_IO

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
#define nl '\n'
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;

int n;
int test[1001];
map<pii, int> memo;
map<pii, pii> Prev;
map<pii, int> value;
int query() {
	cout << "? ";
	for (int i = 1; i <= n; i++)
		cout << test[i];
	cout << endl;
	int diff;
	cin >> diff;
	return diff;
}
void find(int left, int right, int& pos0, int& pos1) {
	//cerr << "Find " << left << " " << right << endl;
	if (right < left) return;
	for (int i = left; i <= right; i++) {
		test[i] = !test[i];
	}
	pii curr = pii(left,right);
	int diff = memo[curr] = query();
	// value stores number of stuff opposite of test[left]
	if (left == 1 && right == n) {
		value[curr] = diff;
	} else {
		//cerr << "valueprev: " << value[Prev[curr]] << endl;
		diff -= memo[Prev[curr]];
		//cerr << "diff: " << diff << endl;
		value[curr] = (diff + right-left+1)/2;
	}
	//cerr << "value: " << value[curr] << endl;
	// yep
	if (value[curr] == right-left+1 || value[curr] == 0) {
		if (value[curr] == right-left+1) {
			if (test[left] == 0) pos1 = left;
			else pos0 = left;
		} else {
			if (test[left] == 0) pos0 = left;
			else pos1 = left;
		}
		if (pos0 && pos1) {
			return;
		} else {
			//cerr << "pos0 pos1: " << pos0 << " " << pos1 << endl;
			// check other side of Prev
			//cerr << "check other side" << endl;
			if (left == Prev[curr].first) {
				left = right+1;
				right = Prev[curr].second;
			} else {
				right = left-1;
				left = Prev[curr].first;
			}
			if (left == right) {
				if (!pos0) pos0 = left;
				else pos1 = left;
				return;
			} else {
				int mid = (left+right)/2;
				memo[pii(left,right)] = memo[curr];
				Prev[pii(left,mid)] = pii(left,right);
				find(left, mid, pos0, pos1);
			}
		}
	} else {
		// split again
		int mid = (left+right)/2;
		Prev[pii(left,mid)] = curr;
		find(left, mid, pos0, pos1);
	}
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	int left, right;
	cin >> n;
	memset(test, 0, sizeof(test));
	int pos0, pos1;
	pos0 = pos1 = 0;
	find(1, n, pos0, pos1);
	cout << "! " << pos0 << " " << pos1 << endl;

	return 0;
}