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

const string ALPH = "qwertyuioplkjhgfdsazxcvbnm";

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    vector <pair <char, int>> x = {{s[0], 1}};
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == x.back().first) ++x.back().second;
        else {
            x.push_back({s[i], 1});
        }
    }
    for (int i = 0; i < x.size(); ++i) {
        if (x[i].first == 1) {
            cout << x[i].second;
        }
        else {
            set <char> forb;
            forb.insert(x[i].first);
            if (i != (int)x.size() - 1) {
                forb.insert(x[i + 1].first);
            }
            char c = '@';
            for (int i = 0; i < 26; ++i) {
                if (!forb.count(ALPH[i])) {
                    c = ALPH[i];
                    break;
                }
            }
            for (int j = 0; j < x[i].second; ++j) {
                if (j % 2 == 0) {
                    cout << x[i].first;
                }
                else {
                    cout << c;
                }
            }
        }
    }
}