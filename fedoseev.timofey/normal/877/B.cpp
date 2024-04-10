# include <iostream>
# include <vector>
# include <set>
# include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector <int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i < n + 1; ++i) {
        pref[i] = pref[i - 1];
        if (s[i - 1] == 'a') ++pref[i];
    }
    int best_ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n + 1; ++j) {
            best_ans = max(best_ans, pref[i] + pref[n] - pref[j] + j - i - (pref[j] - pref[i]));
        }
    }
    cout << best_ans << endl;
}