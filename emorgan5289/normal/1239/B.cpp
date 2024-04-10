#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    string s; fin >> s;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        a[i] = (i == 0 ? 0 : a[i-1]) + (s[i] == '(' ? 1 : -1);
        m = min(m, a[i]);
    }
    if (a[n-1] != 0) {
        cout << "0\n1 1\n"; return 0;
    }
    int z = 0, cz = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        a[i] -= m;
        if (a[i] == 0) {
            z = i; cz++;
        }
    }
    int out = cz;
    rotate(a.begin(), a.begin()+z+1, a.end());
    debug(a);
    int c = 0, l = 0;

    // 0
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            if (c+cz > out) {
                out = c+cz; x = l, y = i;
            }
            c = 0; l = i+1;
        }
        if (a[i] == 2) c++;
    }

    // -1
    c = 0, l = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (c > out) {
                out = c; x = l, y = i;
            }
            c = 0; l = i+1;
        }
        if (a[i] == 1) c++;
    }
    debug(x, y);
    cout << out << "\n" << ((x+z+1)%n)+1 << " " << ((y+z+1)%n)+1 << "\n";
}