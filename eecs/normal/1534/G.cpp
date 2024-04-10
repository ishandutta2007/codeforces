#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> V;
priority_queue<int> L;
priority_queue<int, vector<int>, greater<int>> R;

int main() {
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        V.emplace_back(x + y, x - y);
    }
    sort(V.begin(), V.end());
    L.push(0), R.push(0);
    int lst = 0, shift = 0;
    long long ans = 0;
    for (auto p : V) {
        int x = p.first, y = p.second;
        shift += x - lst; // shift = x
        int lb = L.top() - shift, rb = R.top() + shift;
        if (y < lb) {
            L.push(y + shift), L.push(y + shift);
            L.pop(), R.push(lb - shift);
            ans += abs(lb - y); // opt = lb
        } else if (y > rb) {
            R.push(y - shift), R.push(y - shift);
            R.pop(), L.push(rb + shift);
            ans += abs(rb - y); // opt = rb
        } else {
            L.push(y + shift), R.push(y - shift);
        }
        lst = x;
    }
    printf("%lld\n", ans >> 1);
    return 0;
}