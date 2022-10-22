#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 7;
const int INF = 1e18 + 7;
int n;
int a[N];
vector <int> num[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        num[a[i]].push_back(i);
    }   
    int ans = INF;
    int p1 = -1, p2 = -1;
    for (int i = 0; i < N; ++i) {
        if (num[i].size() > 1 && i < ans) {
            ans = i;
            p1 = num[i][0]; p2 = num[i][1];
        }   
    }   
    for (int gcd = 1; gcd < N; ++gcd) {
        int a = -1, p = -1;
        for (int i = gcd; i < N; i += gcd) {
            if (num[i].size()) {
                if (a != -1) {
                    if (a * i / gcd < ans) {
                        ans = a * i / gcd;
                        p1 = p; p2 = num[i][0];
                    }   
                    break;
                }   
                else {
                    a = i;
                    p = num[i][0];
                    continue;
                }   
            }   
        }   
    }   
    if (p2 < p1) swap(p1, p2);
    cout << p1 + 1 << ' ' << p2 + 1 << '\n';
}