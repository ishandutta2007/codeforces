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
bool check(string a, string b) {
    return a[1] == b[1] && a[0] == b[0] - 1;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    string a[3];
    for (int i = 0; i < 3; ++i)
        cin >> a[i];
    sort(a, a + 3);
    if (a[0] == a[1] && a[0] == a[2]) {
        cout << "0\n";
        exit(0);
    }   
    if (check(a[0], a[1]) && check(a[1], a[2])) {
        cout << "0\n";
        exit(0);
    }   
    if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2]) {
        cout << "1\n";
        exit(0);
    }   
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (check(a[i], a[j])) {
                cout << "1\n";
                exit(0);
            }   
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (a[i][1] == a[j][1] && a[i][0] + 2 == a[j][0]) {
                cout << "1\n";
                exit(0);
            }   
    cout << "2\n";
}