#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define db(x) cout << #x << " = " << x << endl

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = (int)1e9;
const int MAXN = 100500;

int n, t, k, d, T;
int cnt[2];
int ans[2];
                
void chk(int i) {
    if (ans[i] == -1) {
        if (cnt[i] >= n) {
            ans[i] = T;   
        }
    }
}

int main() {

    while (cin >> n >> t >> k >> d) {
        cnt[0] = cnt[1] = 0;
        ans[0] = ans[1] = -1;
        for (T = 1; ans[0] == -1 || ans[1] == -1; T++) {
            if (T % t == 0) {
                forn(i, 2) {
                    cnt[i] += k;
                    chk(i);
                }
            }
            if (T > d && (T - d) % t == 0) {
                cnt[1] += k;
                chk(1);   
            }
        }
        cout << (ans[0] <= ans[1] ? "NO\n" : "YES\n");
    }
    
    return 0;
}