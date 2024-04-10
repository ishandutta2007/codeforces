#include <iostream>
#include <ctime>
#include <set>
#include <fstream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pii pair <int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define problem "test"
typedef long long ll;

const int INF = int(1e9) + 7;
const ll INFll = ll(1e18) + 7;
//const int SZ = 470;
const double eps = 1e-15;

using namespace std;



int n, a[200005], b[200005], SZ;

int stupid(int k){
	int c = 2, ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < k && c <= n; j++, c++){
			if (a[c] < a[i]) ans++;
		}
	}
	return ans;
}

int main(){
//  ifstream cin (problem".in");
//  ofstream cout(problem".in");
	cin >> n;
	SZ = 5 + int(sqrt(n * 1.));
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= min(SZ, n - 1); i++){
		cout << stupid(i) << " ";
	}
	if (SZ < n - 1){
		int cnt = 0;
		for (int i = 2; i <= SZ + 1; i++){
			if (a[i] < a[1]) cnt++;
		}
		for (int i = SZ + 2; i <= n; i++){
			if (a[i] < a[1]) cnt++;
			b[i - 1] = cnt;
		}
		for (int i = 2; i <= SZ + 2; i++){
			int l = min(n + 1, (SZ + 1) * (i - 1) + 2), r = min(n + 1, (SZ + 1) * i + 1);
			int cnt = 0;
			for (int j = l; j <= min(n, r); j++){
				if (a[j] < a[i]) cnt++;
			}
			for (int j = SZ + 1; j < n; j++){
				int nl = min(n + 2, j * (i - 1) + 2), nr = min(n + 2, j * i + 1);
				for (int k = l; k < nl; k++){
					if (k <= n && a[k] < a[i]) cnt--;
				}
				for (int k = r + 1; k <= nr; k++){
					if (k <= n && a[k] < a[i]) cnt++;
				}
				b[j] += cnt;
				l = nl;
				r = nr;
				if (l > n) break;
			}
		}
		for (int i = SZ + 1; i < n; i++) cout << b[i] << " ";
	}
}