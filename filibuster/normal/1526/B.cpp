#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<li, li>;

const int INF = 1e9 + 14;
const int M = 998244353;
const int N = 1000 + 13;

/*
1
AN
*/

void solve() {
    int x;
    cin >> x;


    for(int i = 0; i < 11; i++) {
        if(x % 11 == 0) {
            cout << "YES" << endl;
            return;
        }
        x -= 111;
        if(x < 0) {
            break;
        }
    }

    cout << "NO" << endl;
}

//set<int> st;
//
//void calc(int x, int d) {
//    if(x > N || d > N)
//        return;
//
//    st.insert(x);
//    calc(x + d, d);
//    calc(x, d * 10 + 1);
//}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();

//    calc(0, 11);
//
//    for(auto x : st)
//        cout << x  << ' ';
//    cout << endl;

}