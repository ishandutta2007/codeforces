#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

/*
5 10
99.99
*/

void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int k;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') {
            k = i;
        } else {
            a.push_back(s[i] - '0');
        }
    }

    int j = -1;
    for(int i = k; i < a.size(); i++)
        if(a[i] >= 5) {
            j = i;
            break;
        }

    if(j == -1) {
        cout << s << endl;
        return;
    }

    while(m > 0) {
        m--;
        a.erase(a.begin() + j, a.end());
        if(a.empty()) {
            a.push_back(1);
        } else {
            while(true) {
                j--;
                if(j < 0) {
                    a.insert(a.begin(), 1);
                    j = 0;
                    k++;
                    break;
                } else {
                    a[j]++;
                    if(a[j] == 10) {
                        a[j] = 0;
                    } else {
                        break;
                    }
                }
            }
        }

//        for(auto x : a)
//            cout << x << ' ';

        if(a[j] < 5 || j < k)
            break;
    }

    if(a.size() <= k) {
        for(auto x : a)
            cout << x;
        for(int i = a.size(); i < k; i++)
            cout << 0;
        return;
    }

    bool fl = false;
    for(int i = 0; i < a.size(); i++) {
        if(i == k && !fl) {
            cout << '.';
            fl = true;
            i--;
            continue;
        } else {
            cout << a[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}