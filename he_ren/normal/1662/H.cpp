#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

inline int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	fin >> T;
	while (T --) {
		int w, h;
		fin >> w >> h;
		std::vector <int> ans;
		ans.push_back(1);
		auto add = [&] (int x) {
			for (int i = 1; i * i <= x; ++ i) {
				if (x % i == 0) {
					ans.push_back(i);
					ans.push_back(x / i);
				}
			}
		};
		rep(mask, 1 << 4) {
			int l1 = w - (mask >> 0 & 1) - (mask >> 1 & 1);
			int l2 = h - !(mask >> 1 & 1) - !(mask >> 2 & 1);
			int l3 = w - (mask >> 2 & 1) - (mask >> 3 & 1);
			int l4 = h - !(mask >> 3 & 1) - !(mask >> 0 & 1);
			int g = gcd(gcd(l1, l2), gcd(l3, l4));
			add(g);
		}
		std::sort(ans.begin(), ans.end());
		ans.erase(std::unique(ans.begin(), ans.end()), ans.end());
		fout << ans.size();
		rep(i, ans.size()) fout << " " << ans[i];
		fout << endl;
	}
	return 0;
}