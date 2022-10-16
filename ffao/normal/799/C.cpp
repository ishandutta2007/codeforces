#include <bits/stdc++.h>
using namespace std;

int n,co,di;
vector< pair<int, int> > coins, diamonds;
vector< int > mc, md;

int main() {
	scanf("%d %d %d", &n, &co, &di);

	for (int i = 0; i < n; i++) {
		int b,p;
		char t;

		scanf("%d %d %c", &b, &p, &t);
		pair<int, int> tp = {p, b};
		if (t == 'C') coins.push_back(tp);
		else if (t == 'D') diamonds.push_back(tp);
	}

	sort(coins.begin(), coins.end());
	sort(diamonds.begin(), diamonds.end());

	int ans = 0;
	int j = -1;
	
	for (int i = 0; i < coins.size(); i++) {
		while (j >= 0 && coins[i].first + coins[j].first > co) j--;

		if (j != -1) ans = max(ans, coins[i].second + mc[j]);
		j++;
		
		if (mc.empty()) mc.push_back(coins[i].second);
		else mc.push_back( max(coins[i].second, mc.back()) );
	}

	j = -1;
	for (int i = 0; i < diamonds.size(); i++) {
		while (j >= 0 && diamonds[i].first + diamonds[j].first > di) j--;

		if (j != -1) ans = max(ans, diamonds[i].second + md[j]);
		j++;

		if (md.empty()) md.push_back(diamonds[i].second);
		else md.push_back( max(diamonds[i].second, md.back()) );
	}

	int bc = -1, bd = -1;
	for (int i = 0; i < coins.size(); i++) {
		if (coins[i].first > co) break;
		if (bc == -1 || coins[i].second > coins[bc].second) bc = i;
	}
	for (int i = 0; i < diamonds.size(); i++) {
		if (diamonds[i].first > di) break;
		if (bd == -1 || diamonds[i].second > diamonds[bd].second) bd = i;
	}

	if (bd != -1 && bc != -1) ans = max(ans, coins[bc].second + diamonds[bd].second);
	printf("%d\n", ans);
}