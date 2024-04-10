#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
#define SZ 100
int N;
string S;
int P[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	// using namespace std::chrono;
	// LL ms = duration_cast< milliseconds >(
	//     system_clock::now().time_since_epoch()
	// ).count();

	cin >> S;
	N = S.length();
	for (int i = 0; i < N; i++)
		P[i + 1] = P[i] + (S[i] - '0');

	LL ans = 0;
	for (int q = 1; q < SZ; q++) {
		unordered_map<int, int> m;
		int cur = 0;
		++m[0];
		for (int i = 0; i < N; i++) {
			cur += q * (S[i] - '0') - 1;
			ans += m[cur]++;
		}
	}

	// handle quotients >= SZ (sqrt N)
	int last = -1;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		// if (S[i] == '1') {
		// 	// ok this is my current 1 guy
		// 	int zb = i - last - 1; // prior zeros
		// 	int b1 = P[i];
		// 	int minr = last + SZ;
		// 	if (minr <= i) {
		// 		ans += 
		// 	}
		// 	// len / (P[j] - b1)

		// 	last = S[i];
		// }
		if (S[i] == '1')
			v.push_back(i);
	}

	auto it = v.begin();
	for (int i = 0; i < N; i++) {
		while (it != v.end() && *it < i)
			++it;
		if (it == v.end())
			break;
		// it is now at the first index
		int j = it - v.begin();
		int num = 1; // number of 1s
		while (j < v.size() && num * SZ <= N) {
			// cout << i << ' ' << v[j] << endl;
			int s = max(v[j] - i + 1, num * SZ);
			int e = (j < v.size() - 1 ? v[j + 1] : N) - i; // longest length

			if (s <= e) // num * SZ too big
				ans += e / num - (s - 1) / num;

			++num, ++j;
		}
	}

	// LL ms2 = duration_cast< milliseconds >(
	//     system_clock::now().time_since_epoch()
	// ).count();

	// cout << ms2 - ms << endl;

	cout << ans << endl;
	return 0;
}