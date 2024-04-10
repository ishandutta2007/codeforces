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
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 100228;


int n, q;
ll cnt[MAXN];
ll cnt1[MAXN];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> cnt[i];
	}
	for (int it = 0; it < q; it++) {
		int t;
		cin >> t;
		if (t == 1) {
			int pos;
			ll val;
			cin >> pos >> val;
			cnt[pos] = val;
		} else {
			int x;
			ll k;
			cin >> x >> k;
			for (int i = 0; i < n; i++) {
				cnt1[i] = cnt[i];
			}
			ll ret = 0;
			ll cur = 0;
			for (int i = 0; i <= x; i++) {
				cur += cnt1[i];
			}
			while (true) {
				if (cur >= k) {
					break;
				}
				for (int i = x + 1; i < n; i++) {
					ll s = min(cnt1[i], (k - cur) / (1LL << (i - x)));
					ret += s * ((1LL << (i - x))-1);
					cur += s * (1LL << (i - x));
					cnt1[i] -= s;
					cnt1[x] += s * (1LL << (i - x));
				}
				ll sum = 0;
				for (int i = 0; i <= x; i++) {
					sum += (1LL << i) * cnt1[i];
				} 
				if (sum >= k){
					ret += k - cur;
					break;
				}
				int uk = x + 1;
				while (uk < n && cnt1[uk] == 0) {
					uk++;
				}
				if (uk == n) {   
					ret = -1;
					break;
				}
				ret += uk - x;
				cur += 2;
				cnt1[x] += 2;
				for (int i = x + 1; i < uk; i++) {
					cnt1[i]++;
				}
			}
			cout << ret << '\n';
		}
	}
}