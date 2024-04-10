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
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    // 11 - 10
    // 01 - 11

    // 000
    // 011

    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()) {
        cout << "NO\n";
        exit(0);
    }   

    int a1 = 0;
    for (char c : a)
        a1 += c == '1';
    int b1 = 0;
    for (char c : b)
        b1 += c == '1';

    a1 = (bool)a1;
    b1 = (bool)b1;
                
    if (a1 ^ b1) 
        cout << "NO\n";
    else
        cout << "YES\n";
}