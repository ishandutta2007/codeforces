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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	int cc = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 0)
			cc++;

	sort(all(a));
	vector<int> b = a, c;
	b.resize(unique(all(b)) - b.begin());
	c.resize(b.size());
	for (int i = 0; i < n; i++){
		c[lower_bound(all(b), a[i]) - b.begin()]++;
	}
	int sz = c.size();

	int ans = max(1, cc);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i == j)
				continue;
			if (a[i] == 0 && a[j] == 0)
				continue;

			vector<int> lol;
			int x = a[i], y = a[j];
			lol.push_back(lower_bound(all(b), x) - b.begin());
			lol.push_back(lower_bound(all(b), y) - b.begin());
			c[lol[0]]--;
			c[lol[1]]--;
			while (true){
				x += y;
				swap(x, y);
				int index = lower_bound(all(b), y) - b.begin();
				if (index < sz && b[index] == y && c[index] > 0){
					c[index]--;
					lol.push_back(index);
				} else {
					break;
				}
			}
			ans = max(ans, (int)lol.size());
			for (auto x : lol)
				c[x]++;
		}
	}

	cout << ans << "\n";

	return 0;
}