#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        string s;
        cin >> s;
        string a, b;
        for (char c : ranges::reverse_view(s)) {
            if (a.empty() or c <= a.back()) a += c;
            else b += min(c + 1, (int)'9');
        }
        ranges::reverse(a);
        ranges::sort(b);
        ranges::merge(a, b, s.begin());
        cout << s << "\n";
    }
}