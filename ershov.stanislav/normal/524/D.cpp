#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

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

int a[400000];
vector<pair<int, int> > v;

int main()
{
#ifdef DEBUG
	freopen("in.txt", "r", stdin);
#endif

    int n, m, t;
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int h = 0, mm = 0, sec = 0;
        h += s[0] - '0';
        h*=10;
        h += s[1] - '0';

        mm += s[3] - '0';
        mm*=10;
        mm += s[4] - '0';

        sec += s[6] - '0';
        sec*=10;
        sec += s[7] - '0';
        sec+=100000;
//        cout << h << ' ' << mm << ' ' << sec << endl;
        v.pb(mp(h * 60 * 60 + mm * 60 + sec, 0));
    }
    int i = 100000, j = 100000 - t + 1;
    int cur = 0;
    int mx = 0;
    int cnt = 0;
    for (int k = 0; k < (int) v.size(); k++) {
//        cout << k.fs << endl;
        while (i < v[k].fs) {
            i++;
            cur += a[i];
        }
        while (j < v[k].fs - t + 1) {
            cur -= a[j];
            j++;
        }
        int r = (int) (lower_bound(all(v), mp(v[k].fs - t + 1, -INF)) - v.begin());
        if (cur + (v[r].sc == false && r < k) < m) {
            a[v[k].fs]++;
            cur++;
            v[k].sc = 1;
            cnt++;
        }
        mx = max(mx, cur);
    }
    if (mx != m) {
        printf("No solution\n");
    } else {
        printf("%d\n", cnt);
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].sc) {
                last++;
            }
            printf("%d\n", last);
        }
    }
	return 0;
}