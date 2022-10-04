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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector <int> cnt1(26), cnt2(26);
    for (int i = 0; i < n; ++i) {
        ++cnt1[s[i] - 'a'];
    }
    for (int i = 0; i < n; ++i) {
        ++cnt2[t[i] - 'a'];
    }
    string res(n, '#');
    int l = 0, r = n - 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            int a = 0, b = 25;
            while (cnt1[a] == 0) ++a;
            while (cnt2[b] == 0) --b;
            if (a < b) {
                res[l++] = 'a' + a;
                --cnt1[a];
            }
            else {
                int nt = (n - i + 1) / 2;
                int c = 0;
                a = 0;
                while (c + cnt1[a] < nt) {
                    c += cnt1[a];
                    ++a;
                }
                res[r--] = 'a' + a;
                --cnt1[a];
            }
        }
        else {
            int a = 25, b = 0;
            while (cnt2[a] == 0) --a;
            while (cnt1[b] == 0) ++b;
            if (a > b) {
                res[l++] = 'a' + a;
                --cnt2[a];
            }
            else {
                int nt = (n - i + 1) / 2;
                int c = 0;
                a = 25;
                while (c + cnt2[a] < nt){
                    c += cnt2[a];
                    --a;
                }
                res[r--] = 'a' + a;
                --cnt2[a];
            }
        }
    }
    cout << res << '\n';
}