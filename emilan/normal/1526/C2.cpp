#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    priority_queue<int> pq;
    ll hp = 0;
    int pos = 0;
    for (int x : a) {
        if (x >= 0) {
            hp += x;
            pos++;
        } else {
            if (hp + x < 0) {
                if (!pq.empty() && x > -pq.top()) {
                    hp += pq.top() + x;
                    pq.pop();
                    pq.push(-x);
                }
            } else {
                hp += x;
                pq.push(-x);
            }
        }
    }

    cout << pos + pq.size();
}