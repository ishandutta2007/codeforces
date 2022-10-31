#pragma comment (linker, "/STACK:10000000000")

#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
#include <algorithm>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define pll pair <ll, ll>
#define fs first
#define sc second
#define INF (1e9 + 7)
#define INFll (1e18 + 7)
#define sort stable_sort


using namespace std;

ll n, m, ans = -1, best = INFll;
pll a[4];


int main(){
//    ifstream cin("input.txt");
//    ofstream cout ("output.txt");
    a[0].first = INFll; a[0].second = INFll;
    a[1].first = INFll; a[1].second = -INFll;
    a[2].first = -INFll; a[2].second = INFll;
    a[3].first = -INFll; a[3].second = -INFll;
    cin >> n >> m;
    int c;
    cin >> c;
    for (int i = 0; i < c; i++){
        ll q, w;
        cin >> q >> w;
        if (a[0].first + a[0].second > q + w) a[0] = mp(q, w);
        if (a[1].first + abs (a[1].second - m) > q + abs(m - w)) a[1] = mp(q, w);
        if (abs(n - a[2].first) + a[2].second > abs (n - q) + w) a[2] = mp(q, w);
        if (abs (n - a[3].first)  + abs ( a[3].second - m) > abs (n - q) + abs (m - w)) a[3] = mp(q, w);
    }
    cin >> c;
    for (int i = 0 ; i < c; i++){
		ll q, w, d = 0;
		cin >> q >> w;
		for (int j = 0; j < 4; j++){
			d = max(d, abs(q - a[j].first) + abs(w - a[j].second));
		}
		if (d < best) {
			best = d;
			ans = i + 1;
		}
    }
	cout << best << '\n' << ans << '\n';
    return 0;
}