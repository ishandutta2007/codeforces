#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

typedef long long ll;
typedef unsigned long long ull;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; std::cin >> T;
	while (T--){
		int n; std::string s; std::cin >> n >> s;
		std::vector<std::string> ans(n, std::string(n, '='));
		for (int i = 0; i != n; ++i) ans[i][i] = 'X';
		std::vector<int> a;
		for (int i = 0; i != n; ++i) if (s[i] == '2') a.push_back(i);
		if (a.size() == 1 || a.size() == 2){ std::cout << "NO\n";continue; }
		if (a.size() > 2) for (int i = 0; i < a.size(); ++i){
			int x = a[i], y = a[(i + 1) % a.size()];
			ans[x][y] = '+'; ans[y][x] = '-';
		}
		std::cout << "YES\n";
		for (int i = 0; i != n; ++i) std::cout << ans[i] << '\n';
	}
}