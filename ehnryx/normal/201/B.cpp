#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > cars;
vector<int> rarity;

long long f(long long x, long long y) {
	long long temp = 0;
	for (int i = 0; i < rarity.size(); i++)
		temp += rarity[i] * ((cars[i].first-4*x)*(cars[i].first-4*x) + (cars[i].second-4*y)*(cars[i].second-4*y));
	return temp;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	long long x, y;
	int m, n;
	long long temp, rsum, xsum, ysum, t1, t2, t3, t4;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			if (temp) {
				cars.push_back(pair<int,int>(4*j+2, 4*i+2));
				rarity.push_back(temp);
			}
		}
	} // end input
	if (rarity.empty())
		cout << 0 << endl << "0 0" << endl;
	else {
		for (int i = rsum = xsum = ysum = 0; i < rarity.size(); i++) {
			rsum += rarity[i];
			xsum += rarity[i] * cars[i].first;
			ysum += rarity[i] * cars[i].second;
		}
		x = xsum/rsum;
		y = ysum/rsum;
		x /= 4; y /= 4;

		// check (x,y), (x+1,y), (x,y+1), (x+1,y+1)
		t1 = f(x,y);
		t2 = f(x+1,y);
		t3 = f(x,y+1);
		t4 = f(x+1,y+1);
		if (t1 <= t2 && t1 <= t3 && t1 <= t4)
			cout << t1 << endl << y << " " << x << endl;
		else if (t2 <= t3 && t2 <= t4)
			cout << t2 << endl << y << " " << x+1 << endl;
		else if (t3 <= t4)
			cout << t3 << endl << y+1 << " " << x << endl;
		else
			cout << t4 << endl << y+1 << " " << x+1 << endl;
	}
	return 0;
}