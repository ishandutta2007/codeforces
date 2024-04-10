// #define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <string>

// #include <algorithm>
// #define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

signed main() {
//	setup();

    int n;
    cin >> n;
    int s;
    cout << '?' << ' ';
    for(int i = 0; i < n; ++i)
        cout << 0;
    cout << endl;
    cin >> s;
    int l = 0, r = n;
    int lr = 0, rr = n;
    int pos1, pos2;
    int q = 0;
    int last = -1;
    while(r - l != 1) {

        cout << '?' << ' ';
        ++q;
        int m = (l + r) / 2;
        //cout << l << ' ' << m << endl;
        for(int k = 0; k < l; ++k)
            cout << 0;
        for(int k = l; k < m; ++k)
            cout << 1;
        for(int k = m; k < n; ++k)
            cout << 0;
        cout << endl;
        int kol;
        cin >> kol;
        int u = m - l;
        if (s - kol == (m - l)) {
            lr = max(0, l - m), rr = min(n, r + m);
            break;
        }
        if (kol - s == (m - l))
            l = m;
        else
            r = m;
    }
    pos1 = l;

    while(rr - lr != 1) {
        //cout << lr << ' ' << rr << '\n';
        cout << '?' << ' ';
        ++q;
        int m = (lr + rr) / 2;
        for(int k = 0; k < lr; ++k)
            cout << 0;
        for(int k = lr; k < m; ++k)
            cout << 1;
        for(int k = m; k < n; ++k)
            cout << 0;
        cout << endl;
        int kol;
        cin >> kol;
        if (kol - s == (m - lr)) {
            pos2 = lr;
            break;
        }
        if (s - kol == (m - lr))
            lr = m;
        else
            rr = m;
    }
    //cout << l << ' ' << lr << ' ' << r << ' ' << rr << '\n';
    if (q > 15)
        return 1;
    pos2 = lr;
    cout << '!' << ' ' << pos2 + 1 << ' ' << pos1  + 1 << endl;

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}