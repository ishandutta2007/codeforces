#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set <int> a1;
    set <int> a2;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a1.insert(x);
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a2.insert(x);
    }
    long long cnt = 0;
    for (auto i : a1) {
        for (auto j : a2) {
            int t = i ^ j;
            if (a1.count(t) || a2.count(t)) ++cnt;
        }
    }
    if (cnt & 1) cout << "Koyomi" << endl;
    else cout << "Karen" << endl;
}