#include <algorithm>
#include <iostream>

typedef long long ll;
typedef unsigned long long ull;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; std::cin >> T;
	while (T--){
		int n; std::string s; std::cin >> n >> s;
		bool fl = false;
		for (int i = 1; i != n; ++i) if (s[i - 1] != s[i]){ std::cout << i << ' ' << i + 1 << '\n'; fl = true; break; }
		if (!fl) std::cout << "-1 -1\n";
	}
}