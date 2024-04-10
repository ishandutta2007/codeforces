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
    int k; fin >> k;

    cout << "3 2\n";
    int h = 1 << (32 - __builtin_clz(k));
    cout << (2*h-1) << " " << h << "\n";
    cout << (h-1) << " " << (2*h-1) << "\n";
    cout << 0 << " " << k << "\n";
}