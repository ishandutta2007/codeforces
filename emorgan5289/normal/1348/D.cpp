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
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n; n--;
        vector<int> out = {1};
        while (n > 0) {
            out.pb(min(n, 2*out.back()));
            n -= out.back();
        }
        sort(all(out));
        cout << out.size()-1 << "\n";
        for (int i = 0; i < out.size()-1; i++)
            cout << out[i+1]-out[i] << " \n"[i == out.size()-2];
    }
}