#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    //a
    //aabb
    //aabacbbcc
    //aabacadbbcbdccdd
    string s;
    for(int i = 0; i < k; i += 1){
        s += 'a' + i;
        for(int j = i + 1; j < k; j += 1){
            s += 'a' + i;
            s += 'a' + j;
        }
    }
    assert(s.size() == k * k);
    for(int i = 0; i < n; i += 1) cout << s[i % s.size()];
    return 0;
}