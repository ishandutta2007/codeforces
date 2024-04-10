#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const int P = 1e9+7;
const ll lINF = 1e18;

using namespace std;

int cnt, lst;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    string s, s2;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '#') lst = i, cnt--;
        else if (s[i] == ')') cnt--;
        else cnt++;
    }
    //cout << cnt << endl;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == ')') {
            s2.pb(s[i]);
        } else if (s[i] == '#') {
            if (lst == i) {
                for (int j = 0; j <= max(cnt, 0); j++) s2.pb(')');
            } else {
                s2.pb(')');
            }
        }
    }
    //cout << s2 << endl;
    int cur = 0;
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '(') cur++;
        else cur--;
        if (cur < 0) {
            cout << "-1\n";
            return 0;
        }
    }
    if (cur != 0) {
        cout << "-1\n";
        return 0;
    } else {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] =='#') {
                if (lst == i) {
                    cout << max(1, 1+cnt) << endl;
                } else {
                    cout << "1\n";
                }
            }
        }
    }
    return 0;
}