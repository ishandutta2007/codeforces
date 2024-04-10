#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;

using namespace std;

string lower(string str) {
    for (int i = 0; i < (int) str.length(); i++) {
        str[i] = tolower(str[i]);
    }
    return str;
}

int main() {
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int n;
    map<string, int> m;
    m["polycarp"] = 1;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s1, t, s2;
        cin >> s1 >> t >> s2;
        s1 = lower(s1);
        s2 = lower(s2);
        int nxt = m[s2] + 1;
        m[s1] = nxt;
        ans = max(ans, nxt);
    }
    cout << ans << endl;
    return 0;
}