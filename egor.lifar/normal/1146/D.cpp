 /*
 



















 
 */
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
const string FILENAME = "input";
const int MAXN = 100228;


long long minb[MAXN];
long long gg[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 	//read(FILENAME);
	long long m, a, b;
	cin >> m >> a >> b;
	minb[0] = 0;
	for (int i = 1; i < a; i++) {
		minb[i] = 1e18;
		gg[i] = 1e18;
	}
	long long last = 0;
	long long lcnt = 0;
	for (int i = 1; i < a; i++) {
		long long diff = 1LL * b * i;
		long long cnt = (diff + a - 1) / a;
	//	cout << cnt << ' ' << lcnt << endl;
		long long need = cnt - lcnt;
		lcnt = cnt;
		minb[i] = minb[i - 1];
		//cout << need << endl;
		while (need) {
			long long f = (b - last + a - 1) / a;
			if (f > need) {
				last += need * a;
				break;
			}
			need -= f;
			last += f * a;
			//cout << las
			chkmax(minb[i], last);
			last %= b;
		}
	//	cout << last << endl;
		chkmax(minb[i], last);
		//cout << minb[i] << ' ' << need << endl;
	}
	for (int i = 0; i < a; i++) {
		long long kek = (1LL * b * i) % a;
		kek = a - kek;
		kek %= a;
		chkmin(gg[kek], minb[i]);
		//cout << kek << ' ' << minb[i] << endl;
	}
	long long ans = 0;
	for (int i = 0; i < a; i++) {
		if (gg[i] <= m) {
			long long f = (gg[i] - i) / a + 1;
			//cout << gg[i] << endl;
			//cout << f << ' ' << i << ' ' << (m - gg[i] + 1) << endl;
			ans += f * (m - gg[i] + 1);
		//	cout << ans << endl;
			long long kek = gg[i];
			//cout << gg[i] << endl;
			if (kek % a < i) {
				kek += i - kek % a;
			} else {
				kek = kek + a - kek % a;
				kek = kek + i;
			}
			//cout << kek << ' ' << i << endl;
			if (kek > m) {
				continue;
			}
			//cout << kek << ' ' << i << endl;
			long long cnt = (m - kek) / a + 1;
			ans += 1LL * (m + 1) * cnt -1LL * kek * cnt - a * (cnt * (cnt - 1) / 2); 
			//cout << 1LL * (m + 1) * cnt -1LL * kek * cnt - a * (cnt * (cnt - 1) / 2) << endl;
		}
	}	
	cout << ans << '\n';
	return 0; 	
}