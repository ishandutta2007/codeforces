#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<int> b(n), a(2*n, -1); for (auto& x : b) {fin >> x; x--;}
        debug(b);
        for (int i = 0; i < 2*n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (b[j] == i) {
                    if (a[2*j] == -1)
                        a[2*j] = i;
                    else if (a[2*j+1] == -1)
                        a[2*j+1] = i;
                    else {
                        cout << "-1\n"; goto fail;
                    }
                    flag = false;
                }
            }

            if (flag) {
                for (int j = 0; j < 2*n; j++)
                    if (a[j] == -1 && b[j/2] <= i) {
                        a[j] = i; flag = false; break; }
            }

            if (flag) {
                cout << "-1\n"; goto fail;
            }
        }

        for (auto& x : a) cout << x+1 << " ";
            cout << "\n";

        fail:;
    }
}