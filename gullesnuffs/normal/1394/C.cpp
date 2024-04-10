#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
	
vector<pair<int, int>> points;
int ansx, ansy;
int ans = 1e9;

int check(int x, int y) {
	x = max(x, 0);
	y = max(y, 0);
	int ret = 0;
	int z = x - y;
	for (auto it : points) {
		int X = it.first;
		int Y = it.second;
		int Z = X - Y;
		ret = max(ret, abs(x - X));
		ret = max(ret, abs(y - Y));
		ret = max(ret, abs(z - Z));
	}
	if (ret < ans && (x != 0 || y != 0)) {
		//cerr << ret << " " << x << " " << y << endl;
		ans = ret;
		ansx = x;
		ansy = y;
	}
	return ret;
}

int bruteforce() {
	int xmax = -1e9, ymax = -1e9, zmax = - 1e9;
	int xmin = 1e9, ymin = 1e9, zmin = 1e9;
	for (auto it : points) {
		int x = it.first;
		int y = it.second;
		int z = x - y;
		xmax = max(xmax, x);
		ymax = max(ymax, y);
		zmax = max(zmax, x-y);
		xmin = min(xmin, x);
		ymin = min(ymin, y);
		zmin = min(zmin, x-y);
	}
	int ans = 1e9;
	rep(x,xmin,xmax+1)
	rep(y,ymin,ymax+1) {
		//cerr << x << " " << y << ": " << check(x, y) << endl;
		ans = min(ans, check(x, y));		
	}
	return ans;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	/*while (true) {
	ans = 1e9;
	points.clear();*/
	int n;
	cin >> n;
	//n = (rand()%5)+1;
	//cerr << endl << endl << n << endl;
	int xmax = -1e9, ymax = -1e9, zmax = - 1e9;
	int xmin = 1e9, ymin = 1e9, zmin = 1e9;
	rep(i,0,n) {
		string s;
		cin >> s;
		/*int j = (rand()%10)+1;
		rep(k,0,j) {
			s.push_back((rand()%2)?'B':'N');
		}*/
		//cerr << s << endl;
		int x = 0, y = 0;
		for (char c : s) {
			if (c == 'B')
				++x;
			else
				++y;
		}
		points.emplace_back(x, y);
		xmax = max(xmax, x);
		ymax = max(ymax, y);
		zmax = max(zmax, x-y);
		xmin = min(xmin, x);
		ymin = min(ymin, y);
		zmin = min(zmin, x-y);
	}
	int lo = -1, hi = 1e9;
	check(0, 1);
	check(1, 0);
	check(1, 1);
	while (hi - lo > 1) {
		int mid = (lo + hi)/2;
		bool ok = false;
		rep(i,0,12) {
			int x, y;
			if (i == 0) {
				x = xmax - mid;
				y = ymax - mid;
			} else if (i == 1) {
				x = xmax - mid;
				y = x - zmax + mid;
			} else if (i == 2) {
				y = ymax - mid;
				x = y + zmax - mid;
			} else if (i == 3) {
				x = xmax - mid;
				y = ymin + mid;
			} else if (i == 4) {
				x = xmax - mid;
				y = x - zmin - mid;
			} else if (i == 5) {
				y = ymax - mid;
				x = y + zmin + mid;
			} else if (i == 6) {
				x = xmin + mid;
				y = ymax - mid;
			} else if (i == 7) {
				x = xmin + mid;
				y = x - zmax + mid;
			} else if (i == 8) {
				y = ymin + mid;
				x = y + zmax - mid;
			} else if (i == 9) {
				x = xmin + mid;
				y = ymin + mid;
			} else if (i == 10) {
				x = xmin + mid;
				y = x - zmin - mid;
			} else if (i == 11) {
				y = ymin + mid;
				x = y + zmin + mid;
			} 
			x = max(x, 0);
			y = max(y, 0);
			int ret = 1e9;
			rep(a,-1,2)
			rep(b,-1,2)
				ret = min(ret, check(x+a, y+b));
			if (ret <= mid) {
				ok = true;
				break;
			}
		}
		if (ok) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	rep(i,-1,2)
	rep(j,-1,2)
		check(ansx+i, ansy+j);
	cout << ans << endl;
	assert(ans <= 1e6);
	assert(ansx >= 0);
	assert(ansy >= 0);
	assert(ansx > 0 || ansy > 0);
	/*cerr << ansx << " " << ansy << endl;
	cout << "Result: " << check(ansx, ansy) << endl;*/
	assert(check(ansx, ansy) == ans);
	/*cerr << ansx << " " << ansy << endl;
	auto oldans = ans;
	cerr << "Actual: " << bruteforce() << endl;*/
	rep(i,0,ansx)
		cout <<	'B';
	rep(i,0,ansy)
		cout <<	'N';
	cout << endl;
	/*assert(bruteforce() == oldans);
	}*/
}