#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define int ll

using namespace std;

int a[3];

 main(){
#ifdef LOCAL
	//freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a[0] >> a[1] >> a[2];
	/*vector<pair<int, int> > t;
	t.emplace_back(a, 1);
	t.emplace_back(b, 2);
	t.emplace_back(c, 3);
	sort(all(t));*/
	int ban = -1;


	cout << "First" << endl;

	cout << 1 << endl;
	int v;
	cin >> v;
	a[v - 1] += 1;

	vector<pair<int, int> > t;
	for (int i = 0; i < 3; ++i) t.pb({a[i], i + 1});
	sort(all(t));

	if (t[0].y == v) {
		cout << t[2].x - t[1].x << endl;
		int x;
		cin >> x;
		cout << t[1].x - t[0].x + (t[2].x - t[1].x) * 4 << endl;
		//int x;
		cin >> x;
		if (x == t[0].y) {
			cout << t[2].x - t[1].x + t[2].x - t[1].x << endl;
		} else if (x == t[1].y) {
			cout << t[2].x - t[0].x + t[2].x - t[1].x << endl;
		} else assert(0);
		cin >> x;
		//assert(x == 0);
	} else if (t[1].y == v) {
		cout << t[1].x - t[0].x << endl;
		int x;
		cin >> x;
		cout << t[1].x - t[0].x + (t[2].x - t[0].x) * 2 << endl;
		cin >> x;
		if (x == t[0].y) {
			cout << t[2].x - t[0].x << endl;
		} else if (x == t[1].y) {
			cout << t[2].x - t[0].x + t[1].x - t[0].x << endl;
		} else assert(0);
		cin >> x;
		//assert(x == 0);
	} else {
		cout << t[1].x - t[0].x + (t[2].x - t[1].x) * 2 << endl;
		int x;
		cin >> x;
		if (x == t[0].y) {
			cout << t[2].x - t[1].x << endl;
		} else if (x == t[1].y) {
			cout << t[2].x - t[0].x << endl;
		} else assert(0);
		cin >> x;
		//assert(x == 0);
	}

}