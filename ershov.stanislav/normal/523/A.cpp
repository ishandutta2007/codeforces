#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const ll INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

char s[111][111];
char ans[111][111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int w, h;
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ans[j][i] = s[i][j];
        }
    }
    for (int i = 0; i < w; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < h; j++) {
                cout << ans[i][j] << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}