#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 500 + 13;

/*
*/

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        b[a[i]] = i;
    }

    int cur = 1, ans = 1;
    for(int i = 1; i < n; i++) {
        if(b[i - 1] < b[i])
            cur++;
        else
            cur = 1;
        ans = max(ans, cur);
    }


    cout << n - ans << endl;
}