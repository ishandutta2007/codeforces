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

void bad() {
    cout << "Too weak\n";
    exit(0);
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    string s;
    cin >> s;
    int n = s.size();

    if (n < 5)
        bad();
    bool h = 0;
    for (char c : s)
        if ('a' <= c && c <= 'z')
            h = 1;
    if (!h)
        bad();
    h = 0;
    for (char c : s)
        if ('A' <= c && c <= 'Z')
            h = 1;
    if (!h)
        bad();
    h = 0;
    for (char c : s)
        if ('0' <= c && c <= '9')
            h = 1;
    if (!h)
        bad();
    cout << "Correct\n";
}