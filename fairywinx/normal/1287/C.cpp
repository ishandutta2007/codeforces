#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <ctime>
#include <map>
 
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve()
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
 
using namespace std;
 
void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}
 
void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}
 
void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		cout << i.first << ':' << i.second << ' ';
	cout << '\n';
}
 
void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
	srand(time(NULL));
}
 
 
signed main() {
	setup();
	
	int n;
	int ans = 0;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) 
		cin >> a[i];
	int kol0 = 0;
	int kol1 = 0;
	for(int i = 1; i <= n; ++i) {
		bool p = false;
		for(int j = 0; j < n; ++j) {
			if (a[j] == i) {
				p = true;
				break;
			}
		}
		if (!p) {
			if (i % 2 == 0)
				kol0++;
			else 
				kol1++;
		}
	}
 
	if (kol0 + kol1 == n) {
		if (n == 1)
			cout << 0;
		else {
			cout << 1;
		}
		return 0;
	}
 
	for(int i = 0; i < n - 1; ++i) {
		if (a[i] != 0 && a[i + 1] != 0 && (a[i] % 2) != (a[i + 1] % 2))
			++ans;
	}
 
	vector<int> cc;
	vector<int> nn;
	vector<int> sc;
	vector<int> sn;
	vector<int> cn;
 
	if (a[0] == 0) {
		int i = 0;
		while(a[i] == 0) 
			++i;
		if (a[i] % 2 == 0) 
			sc.pb(i);
		else
			sn.pb(i);
	}
	if (a.back() == 0) {
		int i = n - 1;
		while(a[i] == 0) 
			--i;
		if (a[i] % 2 == 0) 
			sc.pb(n - 1 - i);
		else
			sn.pb(n - 1 - i);
	}
	
 
	int kol = 0;
	int s = a[0];
	bool o = false;
	for(int i = 0; i < n; ++i) {
		//cout << a[i] << '-' << kol << ' ';
		if (a[i] == 0 && o) {
			++kol;
		}
		if (a[i] != 0) {
			o = true;
			if (kol != 0) {
				//cout << s << ' ';
				//cout << a[i] << '\n';
				if (s % 2 == 0 && a[i] % 2 == 0) 
					cc.push_back(kol);
				else if (s % 2 == 0 && a[i] % 2 == 1) 
					cn.push_back(kol);
				else if (s % 2 == 1 && a[i] % 2 == 0) 
					cn.push_back(kol);
				else
					nn.push_back(kol);
			}
			kol = 0;
			s = a[i];
		}
	}
	//cout << '\n';
	//cout << kol1 << ' ' << kol0 << '\n';
	sort(all(cc));
	sort(all(nn));
	sort(all(sn));
	sort(all(sc));
 
	for(int i = 0; i < cc.size(); ++i) {
		if (kol0 >= cc[i])
			kol0 -= cc[i];
		else
			ans += 2;
	}
	for(int i = 0; i < nn.size(); ++i) {
		if (kol1 >= nn[i])
			kol1 -= nn[i];
		else
			ans += 2;
	}
	//cout << kol1 << '\n';
	for(int i = 0; i < sn.size(); ++i) {
		if (kol1 >= sn[i])
			kol1 -= sn[i];
		else
			ans += 1;
	}
	for(int i = 0; i < sc.size(); ++i) {
		if (kol0 >= sc[i])
			kol0 -= sc[i];
		else
			ans += 1;
	}
	ans += cn.size();
	cout << ans << '\n';
 
 
	/*cout << 1 << '-';
	for(auto i: cc)
		cout << i << ' ';
	cout << '\n';
	cout << 2 << '-' ;
	for(auto i: nn)
		cout << i << ' ';
	cout << '\n';
	cout <<3 << '-';
	for(auto i: cn)
		cout << i << ' ';
	cout << '\n';
 
	cout << 5 << '-' ;
	for(auto i: sc)
		cout << i << ' ';
	cout << '\n';
	cout <<6 << '-';
	for(auto i: sn)
		cout << i << ' ';
	cout << '\n';*/
}