#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 5000 + 13;

int calc(vector<int> a) {
    int n = a.size();
    if(n == 0)
        return 0;

    int ans = 0;
    vector<int> b;
//    for(int i = 0; i < n; i++) {
//        if(a[i] == 0) {
//            ans += calc(b);
//            b.erase(b.begin(), b.end());
//        } else {
//            b.push_back(a[i]);
//        }
//    }
//
//    if(b.size() != a.size())
//        return ans + calc(b);

    int mn = INF;
    for(int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
    }

    b.erase(b.begin(), b.end());

    ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == mn) {
            ans += calc(b);
            b.erase(b.begin(), b.end());
        } else {
            b.push_back(a[i] - mn);
        }
    }

    return min(n, ans + calc(b) + mn);
}

//int a[N];
//int b[N];



int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
//        b[i] = a[i];
//        mp[a[i]] = i;
    }

    cout << calc(a);

//    sort(b, b + n);
}