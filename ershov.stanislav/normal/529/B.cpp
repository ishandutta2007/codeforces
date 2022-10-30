#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define eb emplace_back

#define next _next
#define prev _prev
#define hash _hash
#define all(s) s.begin(), s.end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

template <class T>
void mout(T b, T e) {
#ifdef DEBUG
    for (T i = b; i != e; i++) {
        cout << *i << ' ';
    }
    cout << endl;
#endif
}

vector<pair<int, int> > p;
int n;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int w, h;
        scanf("%d%d", &w, &h);
        p.eb(w, h);
    }

    int mn = 2e9;
    for (int mh = 1; mh <= 1000; mh++) {
        int can = n / 2;
        int width = 0;
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            if (p[i].fs > mh && p[i].sc > mh) {
                width = 1000000100;
            } else {
                if (p[i].sc > mh) {
                    can--;
                    width += p[i].sc;
                } else {
                    width += p[i].fs;
                    if (p[i].fs <= mh && p[i].fs > p[i].sc) {
                        s.insert(p[i].sc - p[i].fs);
                    }
                }
            }
        }
        if (can >= 0) {
            for (auto j : s) {
                if (can) {
                    width += j;
                    can--;
                }
            }
            if (width < 1000100)  {
                mn = min(mn, width * mh);
            }
        }
    }

    cout << mn << endl;

    return 0;
}