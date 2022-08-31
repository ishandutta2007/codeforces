#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt();
	int a = 0;
	for (int i = 0, j = 1; j < n; i++, j *= 7){
		a++;
	}
	int b = 0;
	for (int i = 0, j = 1; j < m; i++, j *= 7){
		b++;
	}

	if (!a)
		a = 1;
	if (!b)
		b = 1;

	if (a + b > 7){
		puts("0");
		return 0;
	}

	vector<int> cnt[2];
	for (int i = 0; i < 2; i++)
		cnt[i].resize(128);

	for (int i = 0; i < n; i++){
		int mask = 0;
		int x = i;
		bool ok = true;
		for (int j = 0; j < a; j++){
			if (mask & (1 << (x % 7))){
				ok = false;
				break;
			}
			mask |= (1 << (x % 7));
			x /= 7;
		}
		if (ok)
			cnt[0][mask]++;
	}

	long long ans = 0;

	for (int i = 0; i < m; i++){
		int mask = 0;
		int x = i;
		bool ok = true;
		for (int j = 0; j < b; j++){
			if (mask & (1 << (x % 7))){
				ok = false;
				break;
			}
			mask |= (1 << (x % 7));
			x /= 7;
		}
		if (ok)
			cnt[1][mask]++;
	}

	vector<int> msks[2];
	for (int i = 0; i < 128; i++){
		if (__builtin_popcount(i) == a)
			msks[0].push_back(i);
		if (__builtin_popcount(i) == b)
			msks[1].push_back(i);
	}

	for (auto x : msks[0]){
		for (int y : msks[1]){
			if (x & y)
				continue;
			ans += cnt[0][x] * cnt[1][y];
		}
	}

	cout << ans << "\n";

	return 0;
}