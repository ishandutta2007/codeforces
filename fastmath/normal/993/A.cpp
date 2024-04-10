#include <bits/stdc++.h>
   
using namespace std; 
 
#define int long long

pair <int, int> a1, b1, c1, d1;
vector <pair <int, int> > v(4);

bool ch1(pair <int, int> p) {
	int x = p.first; int y = p.second;
	int l, r;
	l = min(a1.first, c1.first);
	r = max(a1.first, c1.first);
	if (x < l || r < x) return 0;
	l = min(a1.second, c1.second);
	r = max(a1.second, c1.second);
	if (y < l || r < y) return 0;
	return 1;
}

bool ch2(pair <int, int> p) {
	int x = p.first; int y = p.second;
	if (x + y < v[0].first + v[0].second) return 0;
	if (x + y > v[2].first + v[2].second) return 0;	
	if (y - x < v[1].second - v[1].first) return 0;
	if (y - x > v[2].second - v[2].first) return 0;
	return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

	cin >> a1.first >> a1.second >> b1.first >> b1.second >> c1.first >> c1.second >> d1.first >> d1.second;	    
	cin >> v[0].first >> v[0].second >> v[1].first >> v[1].second >> v[2].first >> v[2].second >> v[3].first >> v[3].second;	    

	sort(v.begin(), v.end());

	for (int i = -100; i <= 100; ++i) {
		for (int j = -100; j <= 100; ++j) {
		 	pair <int, int> p = {i, j};
		 	if (ch1(p) && ch2(p)) {
		 	 	cout << "YES\n";
		 	 	return 0;
		 	}
		}
	}

	cout << "NO\n";
    return 0;
}