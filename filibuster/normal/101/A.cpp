#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

bool cmp(vector<int>& a, vector<int>& b) {
    return a.size() < b.size();
}

int main() {
    string s;
    cin >> s;

    int n = s.size();

    int k;
    cin >> k;

    vector<vector<int>> a(26);
    for(int i = 0; i < n; i++) {
        a[s[i] - 'a'].push_back(i);
    }

    sort(a.begin(), a.end(), cmp);

    vector<bool> b(n, true);
    int m = 26;
    for(int i = 0; i < a.size(); i++) {
//        cout << i << ' ' << a[i].size() << ' ' << k << endl;
        if(a[i].size() <= k) {
            m--;
            k -= a[i].size();
            for(auto x : a[i])
                b[x] = false;
        } else {
            break;
        }
    }

    cout << m << endl;

    for(int i = 0; i < n; i++)
        if(b[i])
            cout << s[i];

}