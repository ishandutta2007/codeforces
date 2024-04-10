#include<bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;

pair<pair<int, int>, char> s[3];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    int area = 0;
    for (int i = 0; i < 3; i++) {
        cin >> s[i].fs.fs >> s[i].fs.sc;
        s[i].sc = 'A' + i;
        area += s[i].fs.fs * s[i].fs.sc;
        if (s[i].fs.fs < s[i].fs.sc) {
            swap(s[i].fs.fs, s[i].fs.sc);
        }
    }
    for (int i = 1; i < 3; i++) {
        if (s[i] > s[0]) {
            swap(s[i], s[0]);
        }
    }
    if (area != s[0].fs.fs * s[0].fs.fs) {
        cout << -1 << endl;
    } else {
        bool flag = false;
        if (s[1].fs.fs == s[0].fs.fs && s[2].fs.fs == s[0].fs.fs) {
            flag = true;
        }
        if (s[1].fs.sc + s[2].fs.sc == s[0].fs.fs && s[1].fs.fs == s[2].fs.fs) {
            flag = true;
        }
        if (s[1].fs.fs + s[2].fs.sc == s[0].fs.fs && s[1].fs.sc == s[2].fs.fs) {
            flag = true;
        }
        if (s[1].fs.sc + s[2].fs.fs == s[0].fs.fs && s[1].fs.fs == s[2].fs.sc) {
            flag = true;
        }
        if (s[1].fs.fs + s[2].fs.fs == s[0].fs.fs && s[1].fs.sc == s[2].fs.sc) {
            flag = true;
        }
        if (!flag) {
            cout << -1 << endl;
            return 0;
        }
        cout << s[0].fs.fs << endl;
        for (int i = 0; i < s[0].fs.sc; i++) {
            for (int i = 0; i < s[0].fs.fs; i++) {
                cout << s[0].sc;
            }
            cout << endl;
        }
        if (s[1].fs.fs == s[0].fs.fs && s[2].fs.fs == s[0].fs.fs) {
            for (int i = 0; i < s[1].fs.sc; i++) {
                for (int j = 0; j < s[1].fs.fs; j++) {
                    cout << s[1].sc;
                }
                cout << endl;
            }
            for (int i = 0; i < s[2].fs.sc; i++) {
                for (int j = 0; j < s[2].fs.fs; j++) {
                    cout << s[2].sc;
                }
                cout << endl;
            }
        } else if (s[1].fs.sc + s[2].fs.sc == s[0].fs.fs && s[1].fs.fs == s[2].fs.fs) {
            for (int i = 0; i < s[0].fs.fs - s[0].fs.sc; i++) {
                for (int j = 0; j < s[1].fs.sc; j++) {
                    cout << s[1].sc;
                }
                for (int j = 0; j < s[2].fs.sc; j++) {
                    cout << s[2].sc;
                }
                cout << endl;
            }
        } else if (s[1].fs.fs + s[2].fs.sc == s[0].fs.fs && s[1].fs.sc == s[2].fs.fs) {
            for (int i = 0; i < s[0].fs.fs - s[0].fs.sc; i++) {
                for (int j = 0; j < s[1].fs.fs; j++) {
                    cout << s[1].sc;
                }
                for (int j = 0; j < s[2].fs.sc; j++) {
                    cout << s[2].sc;
                }
                cout << endl;
            }
        } else if (s[1].fs.sc + s[2].fs.fs == s[0].fs.fs && s[1].fs.fs == s[2].fs.sc) {
            for (int i = 0; i < s[0].fs.fs - s[0].fs.sc; i++) {
                for (int j = 0; j < s[1].fs.sc; j++) {
                    cout << s[1].sc;
                }
                for (int j = 0; j < s[2].fs.fs; j++) {
                    cout << s[2].sc;
                }
                cout << endl;
            }
        } else if (s[1].fs.fs + s[2].fs.fs == s[0].fs.fs && s[1].fs.sc == s[2].fs.sc) {
            for (int i = 0; i < s[0].fs.fs - s[0].fs.sc; i++) {
                for (int j = 0; j < s[1].fs.fs; j++) {
                    cout << s[1].sc;
                }
                for (int j = 0; j < s[2].fs.fs; j++) {
                    cout << s[2].sc;
                }
                cout << endl;
            }
        }
    }
    return 0;
}