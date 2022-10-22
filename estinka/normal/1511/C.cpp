#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <iomanip>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<int> best(58, -1);
	for (int i = 0; i < n; i++) cin >> a[i], best[a[i]] = (best[a[i]] == -1 ? i : best[a[i]]);
	while (q--)
	{
		int x; cin >> x;
		cout << best[x] + 1 << " ";
		for (int i = 0; i < best.size(); i++) if (i != x && best[i] != -1 && best[i] < best[x]) best[i]++;
		best[x] = 0;
	}cout << "\n";
	return 0;
}