#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
signed main() {
    cout << "? ";
    for (int i = 1; i <= 100; ++i)
        cout << i << ' ';
    cout << endl;
    int a;
    cin >> a;
    cout << "? ";
    for (int i = 0; i < 100; ++i)
        cout << (i << 7) << ' ';
    cout << endl;
    int b;
    cin >> b;
    cout << "! " << ((a >> 7) << 7) + (b & ((1 << 7) - 1)) << endl;
}