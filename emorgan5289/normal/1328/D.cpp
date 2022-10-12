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
    int t; fin >> t;
    while (t--) {
        ll n; fin >> n;
        vector<ll> a(n); for (auto& x : a) fin >> x;
        bool allsame = 1;
        for (ll i = 0; i < n-1; i++)
            allsame &= a[i] == a[i+1];
        if (allsame) {
            cout << "1\n";
            for (ll i = 0; i < n; i++) cout << "1 ";
            cout << "\n"; goto next;
        }
        if (n%2 == 0) {
            cout << "2\n";
            for (ll i = 0; i < n; i++)
                cout << (i%2)+1 << " ";
            cout << "\n"; goto next;
        }
        for (ll i = 0; i < n; i++) {
            if (a[i] == a[(i+1)%n]) {
                cout << "2\n";
                for (ll j = 0; j <= i; j++)
                    cout << (j%2)+1 << " ";
                for (ll j = i+1; j < n; j++)
                    cout << ((j+1)%2)+1 << " ";
                cout << "\n";
                goto next;
            }
        }
        cout << "3\n";
        for (ll i = 0; i < n-1; i++)
            cout << (i%2)+1 << " ";
        cout << "3 \n";

        next:;
    }
}