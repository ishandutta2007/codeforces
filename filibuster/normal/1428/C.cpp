#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 5000;
const int A = 1e6 + 13;

/*
3
177650 578041 907590

329549 45091

*/

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    int ca = 0, cb = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'A') {
            if(cb > 0)
                cb--;
            else
                ca++;
        } else {
            cb++;
        }
    }

    cout << (cb % 2) + ca << endl;

//    vector<int> a;
//    for(int i = 0; i < n; i++) {
//        if(i == 0 || s[i - 1] != s[i])
//            a.push_back(1);
//        else
//            a.back()++;
//    }
//
//    int i = a.size() - 1;
//    if(s[n - 1] == 'a')
//        i--;
//
//    int ans = 0;
//    while(i > 0) {
//
//    }
}

int main() {
    int t;
    cin >> t;

    while(t--)
        solve();
}