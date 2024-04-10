#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef LOCAL
#define debug(...) {\
    std::cout << "[" << __FUNCTION__ << ":" << __LINE__ << "] " << #__VA_ARGS__ << " "  << __VA_ARGS__ << std::endl;\
    }
#else
#define debug(...)
#endif

/*input
8
1 8
1 10
1 6
3
2
1 9
2
3

*/
/*input
6
1 8
1 10
1 8
3
3
3

*/
/*input
8
1 103913
3
1 103913
1 103913
3
1 103913
1 103913
2

*/

bool served[500100] = {};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	queue<pair<int, int>> eil;
	priority_queue<pair<int, int>> peil;
	int nr = 1;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			int x;
			cin >> x;
			pair<int, int> zm = {x, -nr};
			nr++;
			eil.push(zm);
			peil.push(zm);
		}
		else if (t == 2) {
			while (true) {
				pair<int, int> zm = eil.front();
				eil.pop();

				if (served[-zm.second]) {
					continue;
				}

				served[-zm.second] = true;
				cout << -zm.second << " ";
				break;
			}
		}
		else if (t == 3) {
			while (true) {
				pair<int, int> zm = peil.top();
				peil.pop();

				if (served[-zm.second]) {
					continue;
				}

				served[-zm.second] = true;
				cout << -zm.second << " ";
				break;
			}
		}
	}

}