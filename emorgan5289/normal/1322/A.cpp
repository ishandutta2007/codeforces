#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
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
    int n; fin >> n;
    string s; fin >> s;
    int a = 0, b = 0;
    for (char c : s) {
        if (c == '(') a++;
        else b++;
    }
    if (a != b) {
        cout << "-1\n"; return 0;
    }
    int m = 0, d = 0;
    for (char c : s) {
        if (c == '(') d++;
        else d--;
        // debug(d);
        if (d < 0 || d == 0 && c == '(') m++;
    } 
    cout << m << "\n";
}