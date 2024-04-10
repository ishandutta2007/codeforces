#include <bits/stdc++.h>

using namespace std;

int main() {
    // ifstream cin("/home/stefanb/work/platform/src/app/shm_clean/input.txt");
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        int n;
        string s;
        cin >> n >> s;
        int ans = 1;
        char before = 0;
        for (auto ch : s) {
            ans += (before == ')' && ch == ')');
            before = ch;
        }
        cout << ans << "\n";
    }
    return 0;
}