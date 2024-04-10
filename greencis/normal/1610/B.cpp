#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

bool isPalindrome(const vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1 - i; ++i)
        if (v[i] != v[n - 1 - i])
            return false;
    return true;
}

vector<int> removeElement(const deque<int>& d, int x) {
    vector<int> v;
    for (int q : d) {
        if (q != x)
            v.push_back(q);
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        deque<int> d;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            d.push_back(x);
        }
        while (d.size() > 1 && d.front() == d.back()) {
            d.pop_front();
            d.pop_back();
        }
        bool good = d.size() <= 1;
        if (!good) {
            good |= isPalindrome(removeElement(d, d.front()));
            good |= isPalindrome(removeElement(d, d.back()));
        }
        cout << (good ? "YES" : "NO") << endl;
    }
}