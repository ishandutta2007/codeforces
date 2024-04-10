#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

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
        if (n == 1) {
            cout << "-1\n"; continue; 
        }
        int x = (n-1)*2;
        if (x%3 == 0) {cout << "3";} else cout << "2";
        for (int i = 0; i < n-2; i++) cout << "2";
        cout << "3\n";
    }
}