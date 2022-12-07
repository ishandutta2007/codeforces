#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
vector<string> v;
deque<string> q;
vector<string> ans;

int main() {
    mt19937 mt(123);
    forn(i, 100) {
        string s;
        forn(j, 5) {
            s += char('a' + mt() % 26);
        }
        s[0] -= 'a';
        s[0] += 'A';
        v.pb(s);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cin >> n >> k;
    forn(i, k - 1) {
        q.pb(v[i]);
        ans.pb(v[i]);
    }
    int pos = k - 1;
    for (int i = k - 1; i < n; ++i) {
        string cur;
        cin >> cur;
        if (cur[0] == 'Y') {
            q.pb(v[pos]);
            ans.pb(v[pos]);
            ++pos;
        } else {
            q.pb(q.front());
            ans.pb(q.front());
        }
        q.pop_front();
    }
    for (string s : ans) cout << s << ' ';
    cout << endl;
    return 0;
}