#include<cstdio>
#include<set>
#include<map>
using namespace std;
int n;
int it[1 << 18];
int arr[100100];
map<int, set<int>> mp;
void itpush(int x, int val) {
	x += 1 << 17;
	while (x > 0) {
		it[x] += val;
		x /= 2;
	}
}
int itcalc(int start, int end) {
	start += 1 << 17;
	end += 1 << 17;
	int res = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			res += it[start];
			start++;
		}
		if (end % 2 == 0) {
			res += it[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return res;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		itpush(i, 1);
		mp[arr[i]].insert(i);
	}
	long long int ans = 0;
	int p = 0;
	while (mp.size() > 0) {
		int val = mp.begin()->first;
		int s;
		if (mp[val].lower_bound(p) == mp[val].end()) {
			s = *mp[val].begin();
			ans += itcalc(p, n - 1) + itcalc(0, s);
		}
		else {
			s = *mp[val].lower_bound(p);
			ans += itcalc(p, s);
		}
		mp[val].erase(s);
		itpush(s, -1);
		p = s;
		if (mp[val].size() == 0)mp.erase(val);
	}
	printf("%I64d", ans);
	return 0;
}