#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const li INF = 2e18 + 13;
const int M = 1e9 + 7;
const int N = 2000 + 13;

/*
42 42 42

*/



int main() {
    int n;
    cin >> n;

    while(n--) {
        li l, r;
        cin >> l >> r;

        li x = l;
        int ans = 0;
        for(li i = 1; i <= r; i *= 2) {
            if(i & l) {
    //            st.insert(i);
                ans++;
            } else {
                if(x + i <= r) {
                    x += i;
                    ans++;
                } else {
                    break;
                }
            }
        }

        cout << x << endl;
    }
}