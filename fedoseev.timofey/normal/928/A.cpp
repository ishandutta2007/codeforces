#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

string first_sim = "0o";
string second_sim = "il1";

bool similar(char c1, char c2) {
    if (first_sim.find(c1) != -1 && first_sim.find(c2) != -1) return true;
    if (second_sim.find(c1) != -1 && second_sim.find(c2) != -1) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    for (auto &c : s) {
        if ('A' <= c && c <= 'Z') {
            c -= 'A' - 'a';
        }
    }
    int n;
    cin >> n;
    vector <string> base(n);
    for (int i = 0; i < n; ++i) {
        cin >> base[i];
    }
    for (int i = 0; i < n; ++i) {
        string &cur = base[i];
        if (cur.size() != s.size()) continue;
        for (int j = 0; j < cur.size(); ++j) {
            if ('A' <= cur[j] && cur[j] <= 'Z') {
                cur[j] -= 'A' - 'a';
            }
        }
        bool flag = true;
        for (int j = 0; j < cur.size(); ++j) {
            if (!(cur[j] == s[j] || similar(cur[j], s[j]))) {
                flag = false;
            }
        }
        if (flag) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}